//2127405037 zhaopeng
#include"NFA.hpp"
class DFAState
{
public:
	DFAState()
	{
		this->id = -1;
		this->accepted = false;
	}
	DFAState(int id, set<int>nfaStates)
	{
		this->id = id;
		this->nfaStates = nfaStates;
	}

	set<int> getNFAStates()
	{
		return this->nfaStates;
	}
	void setDFATransistion(map<char, int> trans)
	{
		this->dfaTransistion = trans;
	}
	void setAccepted(bool isAccepted)
	{
		this->accepted = isAccepted;
	}
	int getID()
	{
		return this->id;
	}
	bool isAccepted()const
	{
		return this->accepted;
	}

	int getDFATransition(char ch)
	{
		return this->dfaTransistion[ch];
	}
	bool operator<(const DFAState& other)const
	{
		return this->id < other.id;
	}
private:
	int id;
	set<int> nfaStates;
	map<char, int> dfaTransistion;
	bool accepted;


};


class DFA
{
public:
	DFA()
	{
		this->dfaStateCount = 0;
	}
	void lexerStateReset()
	{
		lexerState = startState;
	}
	int lexerTransfer(char character)
	{
		if(alphbets.find(character)==alphbets.end())
			return errorState;
		int nextState= lexerState.getDFATransition(character);
		if(nextState==-1)
			return errorState;
		lexerState = states[nextState];
		return runningState;
	}
	DFA(NFA* originNFA)
	{
		dfaStateCount = 0;
		this->alphbets = originNFA->alphbets;
		this->nfaStartState = originNFA->NFAStart->data;
		this->nfaEndState = originNFA->NFAEnd->data;
		this->NFATransition=originNFA->NFATransition;


		set<set<int>> tempDFAStates;
		map<set<int>, int>tempDFAStateSign;


		map<set<int>, map<char, set<int>>>setTransition;
		map<set<int>, int> NFAStatesToId;
		map<int, set<int>> IdToNFAStates;


		set<int> startNFAState = { nfaStartState },T;
		startNFAState = getEpsilonClosure(startNFAState);
		tempDFAStates.insert(startNFAState);


		bool ans = getUnsigned(tempDFAStates, tempDFAStateSign, T);

		clock_t start, end;
		start = clock();
		while (getUnsigned(tempDFAStates, tempDFAStateSign, T))
		{
			NFAStatesToId[T] = dfaStateCount;
			IdToNFAStates[dfaStateCount] = T;
			tempDFAStateSign[T] = 1;

			dfaStateCount += 1;

			for (char i :alphbets)
			{
				set<int>temp = move(T, i);

				set<int>U = getEpsilonClosure(temp);
				if (U.empty())
					continue;
				tempDFAStates.insert(U);
				setTransition[T][i] = U;

			}
		}
		end = clock();
cout << "NFA to DFA time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

		for (int i = 0; i < dfaStateCount; i++)
		{
			DFAState tempState= DFAState(i, IdToNFAStates[i]);
			set<int>temp = IdToNFAStates[i];
			
			if (temp.find(nfaEndState) != temp.end())
				tempState.setAccepted(true);
			else
				tempState.setAccepted(false);
			
			map<char, int>idTran;
			for (auto ch : alphbets)
			{
				if(setTransition[temp].find(ch)!=setTransition[temp].end())
					idTran[ch] = NFAStatesToId[setTransition[temp][ch]];
				else
					idTran[ch] = -1;
			}
			tempState.setDFATransistion(idTran);
			states.push_back(tempState);
		}


		DFAMinimize();
		lexerState= startState;
	}
	bool match(string inputString)
	{

		DFAState current=startState;
		int len = inputString.size();
		for (int i=0;i< len;i++)
		{
			char c=inputString[i];
			if(alphbets.find(c)==alphbets.end())
				return false;

			int nextID= current.getDFATransition(c);

			if(nextID==-1)
				return false;
			current = states[nextID];
		}
		return current.isAccepted();
	}
	private:

	vector<DFAState> states;
	DFAState startState;
	map<int, map<char, set<int>>>NFATransition;

	int dfaStateCount;
	set<char>alphbets;

	int nfaStartState;
	int nfaEndState;
	DFAState lexerState;

	set<int>move(const set<int>& T, char a)
	{
		set<int> ans;
		for (auto i : T)
		{

			if (NFATransition[i].find(a) !=NFATransition[i].end())
			{
				for (auto j : NFATransition[i][a])
				{
					ans.insert(j);
				}
			}
		}
		return ans;
	}

	bool getUnsigned(const set<set<int>>& tempDFAState, const  map<set<int>, int>& DFAStateSign, set<int>& T)
	{
		for (set<int> i : tempDFAState)
		{
			if (DFAStateSign.find(i) == DFAStateSign.end())
			{
				T = i;
				return true;
			}
		}
	}
	set<int>getEpsilonClosure(set<int> nfaStates)
	{
		set<int> closure;

		stack<int> stk;

		map<int, int> inClosure;

		for (auto i : nfaStates)	stk.push(i);

		while (stk.size())
		{
			auto t = stk.top();
			stk.pop();

			if (NFATransition[t].find(epsilon) !=NFATransition[t].end())
			{
				set<int> temp =NFATransition[t][epsilon];
				for (auto i : temp)
				{
					if (inClosure.find(i) == inClosure.end())
					{
						inClosure[i] = 1;
						closure.insert(i);
						stk.push(i);
					}
				}
			}
		}
		for (auto i : nfaStates)
			closure.insert(i);
		return closure;
	}


	void DFAMinimize()
	{
		set<set<DFAState>>tempAnswer;
		set<DFAState>accepted, unAccepted;
		for (auto i : states)
		{
			if (i.isAccepted())
				accepted.insert(i);
			else
				unAccepted.insert(i);
		}
		tempAnswer.insert(accepted);
		tempAnswer.insert(unAccepted);
		while (partitionStates(tempAnswer)) {};
	
		dfaStateCount = 0;
	
		map<int, int>stateBelong;
		stateBelong[-1] = -1;
	

		for (auto i : tempAnswer)
		{
			for (auto j : i)
			{
				stateBelong[j.getID()]= dfaStateCount;
			}
			dfaStateCount++;
		}

	

		dfaStateCount = 0;
		states.clear();

		for (auto i : tempAnswer)
		{
			DFAState firstState;
			if (!i.empty())
			{
				firstState = *i.begin();
			}
			set<int>tempNFAStates;
			bool accepted;
			map<char, int>tempTran;
			for (auto j : i)
			{
				for (auto k : j.getNFAStates())
					tempNFAStates.insert(k);
			}
		
	

			

			for(auto j:alphbets)
				tempTran[j] = stateBelong[firstState.getDFATransition(j)];
		

			DFAState tempState = DFAState(dfaStateCount++, tempNFAStates);
			tempState.setAccepted(firstState.isAccepted());
			tempState.setDFATransistion(tempTran);
	
			if(tempNFAStates.find(nfaStartState)!= tempNFAStates.end())
				this->startState = tempState;
		
			states.push_back(tempState);
		}
	

		//cout<<"minimize: "<<endl;
		//printTransition();
			
	}

	bool partitionStates(set<set<DFAState>>& T)
	{
		set<set<DFAState>>tempAnswer=T;
		map<set<DFAState>, int>statesNumber;
		map<int, int>stateBelong;
		int number = 0;
		for (auto i : tempAnswer)
		{
			statesNumber[i] = ++number;
			for (auto j : i)
			{
				stateBelong[j.getID()] = number;
			}
		}
		stateBelong[-1] = -1;
		for (auto i : tempAnswer)
		{
			if (i.size() == 1)continue;
			map<vector<int>, set<DFAState>>classifier;
			for (auto state : i)
			{
				vector<int>allTransition;
				for (auto ch : alphbets)
				{
					allTransition.push_back(stateBelong[state.getDFATransition(ch)]);
				}
				classifier[allTransition].insert(state);
			}
			if (classifier.size() >= 2)
			{
				tempAnswer.erase(i);
				for (auto [trans, states] : classifier)
				{
					tempAnswer.insert(states);
				}
				T = tempAnswer;
				return true;
			}
		}
		return false;
	}
	void printTransition()
	{

		cout << "    ";
		for (auto ch : alphbets)
		{
			cout<< ch << " ";

		}
		cout << endl;
		for (auto i : states)
		{
			cout << i.getID() << "   ";
			for (auto ch : alphbets)
			{
				cout << i.getDFATransition(ch) << " ";
			}
			if(i.isAccepted())
				cout << "Accepted";
			else
				cout << "Unaccepted";
			cout << endl;
		}
	}
};