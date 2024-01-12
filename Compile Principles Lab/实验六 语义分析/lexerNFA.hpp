#include "DFA.hpp"

class LexerNFA
{
public:

	LexerNFA(const char* file,const char* out)
	{
		std::cout<<"正在构建词法分析器所需的NFA：\n";
		Start = new NFAState(0);
		NFA* identifierNFA = NFA::buildNFAFromFile("identifier.txt");
		identifierNFA->Preperation();
		clock_t start, end;
		identifierDFA = new DFA(identifierNFA);

		NFA* numbersNFA = NFA::buildNFAFromFile("numbers.txt");
		numbersNFA->Preperation();
		numbersDFA = new DFA(numbersNFA);

		std::cout << "构建完成\n";
		currentCharacter = char();
		currentRow = 1;
		currentColumn = 0;
		inComment = false;
		currentState = runningState;
		IN.open(file);
		OUT.open(out);
		if (!IN.is_open())
		{
			std::cout << "ERROR: file not found" << std::endl;
			return;
		}
		if (!OUT.is_open())
		{
			std::cout << "ERROR: file not found" << std::endl;
		}
	}
	~LexerNFA()
	{
		IN.close();
		OUT.close();
	}
	int run()
	{
		//IN.get(currentCharacter);
		getNextCharacter();
		while (1)
		{
			if (currentCharacter == EOF)
				return acceptedState;
			if (isspace(currentCharacter))
			{
				//handleWhiteSpace();
				getNextCharacter();
				if (currentState == runningState)
					continue;
				else
					return currentState;
			}

			else if (isdigit(currentCharacter))
			{

				handleNumber();
				if (currentState == runningState)
					continue;
				else
					return currentState;
			}
			else if (isalpha(currentCharacter))
			{
				//identifier
				handleIdentifier();
			}
			else if (singleSymbols.find(currentCharacter) != string::npos)
			{
				handleSingleSymbol();
				if (currentState == runningState)
					continue;
				else
					return currentState;
			}
			else if (comparsionSymbols.find(currentCharacter) != string::npos)
			{
				handleComparsion();
				if (currentState == runningState)
					continue;
				else
					return currentState;
			}
			else if (currentCharacter == '/')
			{
				handleComment();
				if (currentState == runningState)
					continue;
				else
					return currentState;
			}
			else
			{
				std::cout << "[Error] Invalid token! line:" << currentRow << " col:" <<currentColumn<<" " << currentCharacter << "\n";
				return currentState = errorState;
			}


		}
	}
private:
	DFA* identifierDFA, *numbersDFA, division;
	NFAState* Start;
	ifstream IN;
	ofstream OUT;
	char currentCharacter;
	int currentRow, currentColumn, currentState;
	bool inComment = false;
	const std::string singleSymbols = "+-*(){};,:";
	const std::string comparsionSymbols = "><=!";
	std::string keywords[10] = { "if", "else", "for", "while", "do", "int", "read", "write" };
	
	void getNextCharacter()
	{
		if (!IN.get(currentCharacter))
		{
			if (inComment)
			{
				std::cout << "[Error] Unclosed comment,line:" << currentRow << " col:" << currentColumn << "\n";
				currentState = errorState;
				return;
			}
			else
				currentState = acceptedState;
			return ;
		}
		else
		{
			if (currentCharacter != '\n')currentColumn++; else { currentRow++; currentColumn = 0; getNextCharacter(); }
			return;
		}
	}

	void handleNumber()
	{


		string number;
		while (1)
		{
			int tempState=numbersDFA->lexerTransfer(currentCharacter);
			if (tempState == runningState)
			{
				number.push_back(currentCharacter);

				getNextCharacter();
				if (currentState == runningState)
					continue;
				else
				{
					if (currentState==errorState)//文件结束,有括号
					{
						return;
					}
					else if (currentState == acceptedState)
					{
						OUT << "NUM " << number <<" " << currentRow<<" "<<currentColumn << endl;
						return;
					}
				}
			

			}
			else
			{
				numbersDFA->lexerStateReset();
				if (isalpha(currentCharacter))
				{
					std::cout << "[Error] Invalid token! line:" << currentRow << " col:" << currentColumn << "\n";
					currentState = errorState;
					return;

				}
				else
				{

						OUT << "NUM " << number << " " << currentRow << " " << currentColumn << endl;
						currentState = runningState;
						return;
				}
			}

				
		}
	}
	void handleSingleSymbol()
	{
		char previousSymbol = currentCharacter;

		OUT <<currentCharacter<<" "<<currentCharacter << " " << currentRow << " " << currentColumn << endl;
		getNextCharacter();

		if (currentState == runningState)
		{
				if (previousSymbol == '*' && currentCharacter == '/')
				{
				std::cout << "[Error] Redundant right comment.line:" << currentRow << " col:" << currentColumn << "\n";
				currentState=errorState;
				}
				else
				{	
					currentState = runningState;
				}
		}
		else
		{
			return;
		}

	}
	void handleComparsion()
	{
		char pre, nxt;
		pre = currentCharacter;


		getNextCharacter();
		if(currentState == acceptedState)
		{
			OUT << pre << " " << pre << " " << currentRow << " " << currentColumn << endl;
			return;
		}
		else if (currentState == errorState)
		{
			return;
		}
		else
		{
			nxt = currentCharacter;
		}



		if (comparsionSymbols.find(nxt) != std::string::npos)
		{
			OUT << pre << nxt << " " << pre << nxt << " " << currentRow << " " << currentColumn << endl;

	
			getNextCharacter();
		}
		else
		{
			OUT << pre << " " << pre << " " << currentRow << " " << currentColumn << endl;
			currentCharacter = nxt;
			currentState = runningState;
			return;
		}
	}
	void handleIdentifier()
	{

		string identifier;
		while (1)
		{
			int tempState = identifierDFA->lexerTransfer(currentCharacter);
			if (tempState == runningState)
			{
				identifier.push_back(currentCharacter);

				getNextCharacter();
				if (currentState == runningState)
					continue;
				else
				{
					handleID(identifier);
					if (currentState == errorState)//文件结束,有括号
					{
						return;
					}
					else if (currentState == acceptedState)
					{

						return;
					}
				}
			}
			else//errorState
			{
				currentState = runningState;
				handleID(identifier);
				identifierDFA->lexerStateReset();
				break;
			}

		}
	}
	void handleComment()
	{

		char pre, nxt;
		pre = currentCharacter;

		getNextCharacter();	
		
		if (currentState == runningState)
		{
			nxt = currentCharacter;
		}
		else
		{
			OUT << "/ / "<< " " << currentRow << " " << currentColumn << endl;
			return;
		}
		if (nxt == '*')
		{
			inComment = 1;

			getNextCharacter();
			if (currentState == runningState)
			{
		
				pre = currentCharacter;

			}
			else
			{
		
				currentState = errorState;
				return;
			}
			while (currentState==runningState)
			{
				getNextCharacter();
				if (currentState == errorState)
				{
				
					return;
				}
				nxt = currentCharacter;
				if (pre == '*' && nxt == '/')
				{
					inComment = 0;
					getNextCharacter();
					break;
				
				}
				pre = nxt;
			}


		}
		else
		{
			OUT << pre << " " << pre << " " << currentRow << " " << currentColumn << endl;
			currentCharacter = nxt;
			currentState = runningState;
			return;
		}

	}
	void handleID(string identifier)
	{
		std::string id = identifier;

		for (auto& i : id)
		{
			if (i >= 'A' && i <= 'Z')
				i += 'a' - 'A';

		}

		for (auto i : keywords)
		{
			if (id == i)
			{
				OUT << i << " " << i << " " << currentRow << " " << currentColumn << endl;
				return;
			}
		}

		OUT << "ID " << identifier << " " << currentRow << " " << currentColumn << endl;
	}
};