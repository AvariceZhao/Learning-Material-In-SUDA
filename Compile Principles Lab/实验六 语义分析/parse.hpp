#include"utility.h"
//#define DEBUG
int TESTparse();
int program();
int compoundStat();
int statement();
int expressionStat();
int expression();
int boolExpr();
int additiveExpr();
int term();
int factor();
int ifStat();
int whileStat();
int forStat();
int writeStat();
int readStat();
int declarationStat();
int declarationList();
int statementList();
char Scanin[300] = "out.txt", Scanout[300] = "out.asm";
std::ifstream fin;
std::ofstream fout;
struct Token
{
    std::string tokenType, tokenValue;
    int row, column;
};
std::ifstream& operator>>(std::ifstream& in, Token& token)
{
    fin >> token.tokenType >> token.tokenValue>> token.row>> token.column;
   // std::cout << "TokenType:" << token.tokenType << "   TokenValue:" << token.tokenValue <<"   Row:"<< token.row<<"  Column:"<<token.column << std::endl;
    return fin;
}
std::iostream& operator<<(std::iostream& out, Token& token)
{
    std::cout << "TokenType:" << token.tokenType << " TokenValue:" << token.tokenValue << std::endl;
    return out;
}
class SymbolTable
{
public:
    map<string, int>symbolTable;//从变量名到地址
    map<int, int>addressValue;//从地址到值
    int insertVariable(string variableName)
	{
        if (symbolTable.find(variableName) != symbolTable.end())
		{
			return -1;
		}
		int siz = symbolTable.size();
		symbolTable[variableName] = siz;
		return siz;
	}

    void LookUpVariable(string variableName, int& addr)
    {
        if (symbolTable.find(variableName) == symbolTable.end())
        {
            addr = -1;
            return;
        }
		addr = symbolTable[variableName];
        return;
   
    }


}variabletable;
extern char Scanout[300];
int lableCount=1;
int getNewLable()
{
	return lableCount++;
}
void setLable(int label)
{
	fout << "LABEL" << label << ":" << endl;
	cout << "LABEL" << label << ":" << endl;
}
void jumpBR(int label)
{
	fout << "BR" << " LABEL" << label << endl;
	cout << "BR" << " LABEL" << label << endl;
}
void jumpBRF(int label)
{
    fout << "BRF" << " LABEL" << label << endl;
    cout << "BRF" << " LABEL" << label << endl;
}
FILE* fp;
// 语法分析程序
int TESTparse()
{
    int es = 0;
    fin.open(Scanin);
    fout.open(Scanout);
    if (!fin.is_open())
    {
        printf("\n Can not open % S\n", Scanout);
        es = 10;
    }
    if (es == 0)
        es = program();
    printf("== Grammer prase result ==\n");
    switch (es)
    {
    case 0:
        printf("Grammar parse success\n");
        break;
    case 10:
        printf("failed to open %s ", Scanout);
        break;
    case 1:
        printf("Unclosed Parentheses Error\n");
        break;
    case 2:
        printf(" declaration Error\n");
        break;
    case 3:
        printf("Missing Semicolon Error\n");
        break;
    case 4:
        printf("Redefinition of variable\n");
        break;
    case 5:
        printf("Missing Left Parenthesis\n");
        break;
    case 6:
        printf("Undefinition of variable\n");
        break;
    case 7:
        printf("\n");
        break;

    case -1:
        printf("Terminal Symbol error\n");
    }
    fin.close();
    return (es);
}
int program()
{

    Token token;
    int es = 0;
    fin >> token;
    if (token.tokenType == "{")
    {
        int es = declarationList();

        if (es > 0)
        {
#ifdef DEBUG
            std::cout << "Error occur in program!\n";
#endif
            return es;
        }
        es = statementList();
        if (es > 0)
        {
#ifdef DEBUG
            std::cout << "Error occur in program!\n";
#endif
            return es;
        }
        fin >> token;
        if (token.tokenType == "}")

            return es;
#ifdef DEBUG
        std::cout << "Error occur in program!\n";
#endif
        return 1;
    }
    else
    {
#ifdef DEBUG
        std::cout << "Error occur in program! expected {\n";
#endif 
        return 1;
    }
}

int compoundStat()
{

    auto tempPosition = fin.tellg();
    Token leftBracketToken, rightBracketToken;
    fin >> leftBracketToken;

    if (leftBracketToken.tokenType != "{")
    {
        fin.seekg(tempPosition);

#ifdef DEBUG
        std::cout << "Error occur in compoundStat!\n";
#endif
        return -1;
    }
    int es = statementList();
    if (es)
    {
#ifdef DEBUG
        std::cout << "Error occur in compoundStat!\n";
#endif
        return es;
    }
    fin >> rightBracketToken;
    if (rightBracketToken.tokenType != "}")
    {
#ifdef DEBUG
        std::cout << "Error occur in compoundStat!\n";
#endif

        return 1;
    }
    return 0;
}
int statement()
{
    Token t;
    auto tmpPosBef = fin.tellg();
    fin >> t;
    fin.seekg(tmpPosBef);
    if (t.tokenType == "if")
        return ifStat();
    if (t.tokenType == "while")
        return whileStat();
    if (t.tokenType == "for")
        return forStat();
    if (t.tokenType == "read")
        return readStat();
    if (t.tokenType == "write")
        return writeStat();
    if (t.tokenType == "{")
        return compoundStat();
    return expressionStat();
}
int expressionStat()
{
    // std::cout << "enter expressionStat\n";
    int es = expression();
    if (es != 0)
    {
        if (es != -1)
        {
#ifdef DEBUG
            std::cout << "Error occur in expressionStat!\n";
#endif
        }
        return es;
    }
    fout << "POP" << endl;
    cout << "POP" << endl;
    Token t;
    fin >> t;
    if (t.tokenType != ";")
    {
#ifdef DEBUG
        std::cout << "Error occur in expressionStat!\n";
#endif
        return 3;
    }
    return 0;
}

int expression()
{
    int es = 0;
    auto begin = fin.tellg();
    Token t1;
    fin >> t1;

    if (t1.tokenType == "ID")
    {
        Token t2;
        fin >> t2;

        int addr = 0;
        variabletable.LookUpVariable(t1.tokenValue, addr);
        if (addr == -1)
		{
			std::cout <<"[ERROR]"<<"row:"<<t1.row<<" col:"<<t1.column << " Undeclared variable " << t1.tokenValue << std::endl;
			return 6;
		}
        if (t2.tokenType == "=")
        {
            es = boolExpr();
            if (es > 0)
            {
#ifdef DEBUG
                std::cout << "Error occur in expression!\n";
#endif
                return es;
            }
            fout<<"STO "<<addr<<std::endl;
            cout<<"STO "<<addr<<std::endl;
        }
        else
        {

            fin.seekg(begin);
            es = boolExpr();
            if (es > 0)
            {
#ifdef DEBUG
                std::cout << "Error occur in expression!";
#endif
                return es;
            }
        }
    }
    else
    {
        fin.seekg(begin);
        es = boolExpr();
    }
    return es;
}
int boolExpr()
{
    int es = additiveExpr();
    if (es != 0)
    {
        if (es != -1)
        {
#ifdef DEBUG
            std::cout << "Error occur in boolExpr!\n";
#endif
        }
        return es;
    }
    auto tmp = fin.tellg();
    Token t;
    fin >> t;
   
    if (t.tokenType == ">" || t.tokenType == "<" || t.tokenType == ">=" || t.tokenType == "<=" || t.tokenType == "==" || t.tokenType == "!=")
    {
     
      
        int es1= additiveExpr();
        if (t.tokenType == ">")
        {
            fout << "GT" << endl;
            cout << "GT" << endl;
        }
        else if (t.tokenType == "<")
        {
            fout << "LES" << endl;
            cout << "LES" << endl;
        }
        else if (t.tokenType == ">=")
        {
            fout << "GE" << endl;
            cout << "GE" << endl;
        }
        else if (t.tokenType == "<=")
        {
            fout << "LE" << endl;
            cout << "LE" << endl;
        }
        else if (t.tokenType == "==")
        {
            fout << "EQ" << endl;
            cout << "EQ" << endl;
        }
        else if (t.tokenType == "!=")
        {
            fout << "NOTEQ" << endl;
            cout << "NOTEQ" << endl;
        }
        return es1;
    }
    fin.seekg(tmp);
    return es;
}
int additiveExpr()
{
    int es = term();
    if (es != 0)
    {
        if (es != -1)
        {
#ifdef DEBUG
            std::cout << "Error occur in additiveExpr!\n";
#endif
        }
        return es;
    }
    auto tmp = fin.tellg();
    Token t;
    fin >> t;

    if (t.tokenType == "+" || t.tokenType == "-")
    {
        es = term();
        if (!term)return es;
        if(t.tokenType=="+")
        {
			fout<<"ADD"<<endl;
			cout<<"ADD"<<endl;
		}
		else
		{
			fout<<"SUB"<<endl;
			cout<<"SUB"<<endl;
		}  
        return es;

    }
    fin.seekg(tmp);
    return es;
}
int term()
{
    int es = factor();
    if (es != 0)
    {
        if (es != -1)
        {
#ifdef DEBUG
            std::cout << "Error occur in term!";
#endif
        }
        return es;
    }
    auto tmp = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType == "*" || t.tokenType == "/")
    {

        int es=factor();
    if (!factor)return es;
    if (t.tokenType == "*")
    {
    fout << "MULT" << endl;
    cout << "MULT" << endl;
    }
    else
    {
    fout << "DIV" << endl;
	cout << "DIV" << endl;
    }
    return es;


    }
    
    fin.seekg(tmp);
    return es;
}
int factor()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;

    if (t.tokenType == "(")
    {
        int es = expression();
        if (es > 0)
        {
#ifdef DEBUG
            std::cout << "Error occur in factor!" << t.row << " " << t.column << " \n";;
#endif
            return es;
        }
        fin >> t;
        if (t.tokenType != ")")
        {
#ifdef DEBUG
            std::cout << "Error occur in factor!" << t.row << " " << t.column << " \n";;
#endif
            return 1;
        }
        else return 0;
    }
    else if (t.tokenType == "ID")
    {
        int es = 0;
        variabletable.LookUpVariable(t.tokenValue, es);
        if (es == -1)
        {
            std::cout << "[ERROR]" << "row:" << t.row << " col:" << t.column << " Undeclared variable " << t.tokenValue << std::endl;
			return 6;
		}
		else
		{
			fout << "LOAD " << es << endl;
			cout << "LOAD " << es << endl;
        }

        return 0;
    }
        
    else if (t.tokenType == "NUM")
    {
        fout << "LOADI " << t.tokenValue << endl;
		cout << "LOADI " << t.tokenValue << endl;
		return 0;
    }
       
    fin.seekg(begin);

    return -1;
}
int ifStat()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "if")
    {
#ifdef DEBUG
        std::cout << "Error occur in ifStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif

        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "(")
    {
#ifdef DEBUG
        std::cout << "Error occur in ifStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif
        return 5;
    }
    int es = expression();
    if (es > 0)
    {
#ifdef DEBUG
        std::cout << "Error occur in ifStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif
        return es;
    }
    fin >> t;
    if (t.tokenType != ")")
    {

#ifdef DEBUG
        std::cout << "Error occur in ifStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif

        return 1;
    }
    int lable1 = getNewLable();
    jumpBRF(lable1);
    es = statement();
    if (es > 0)
    {
#ifdef DEBUG
        std::cout << "Error occur in ifStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif
        return es;
    }
    
    int lable2= getNewLable();
    jumpBR(lable2);
    setLable(lable1);
    auto tmp = fin.tellg();
    fin >> t;
    if (t.tokenType == "else")
    {
        es = statement();
        if (es > 0)
        {
#ifdef DEBUG
            std::cout << "Error occur in ifStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif
            return es;
        }
      
    }
    else
        fin.seekg(tmp);
    setLable(lable2);
    return 0;
}
int whileStat()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "while")
    {
#ifdef DEBUG
        std::cout << "Error occur in whileStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif

        fin.seekg(begin);
        return -1;
    }

    int label1 = getNewLable();
setLable(label1);

    fin >> t;
    if (t.tokenType != "(")
    {
#ifdef DEBUG
        std::cout << "Error occur in whileStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif
        return 5;
    }
    int es = expression();
    if (es > 0)
    {
#ifdef DEBUG
        std::cout << "Error occur in whileStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif

        return es;
    }
    fin >> t;
    if (t.tokenType != ")")
    {
#ifdef DEBUG
        std::cout << "Error occur in whileStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif

        return 1;
    }

    int lable2= getNewLable();
    jumpBRF(lable2);

    es = statement();
    if (es > 0)
    {
#ifdef DEBUG
        std::cout << "Error occur in whileStat!" << "row: " << t.row << " col:" << t.column << " \n";
#endif
        return es;
    }
    jumpBR(label1);
	setLable(lable2);
    return 0;
}
int forStat()
{
   // std::cout << "enter forStat" << " \n";;
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "for")
    {

        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "(") return 5;

    int es;
 
    es = expression();
    if (es > 0) return es;
    fout<<"POP"<<endl;
    cout<<"POP"<<endl;
    fin >> t;
    if (t.tokenType != ";")  return 3;

    int lable1= getNewLable();
setLable(lable1);

    es = expression();
    if (es > 0) return es;
    int lable2= getNewLable();
    int lable3= getNewLable();
    jumpBRF(lable2);
	jumpBR(lable3);
    fin >> t;
    if (t.tokenType != ";")  return 3;

    int lable4= getNewLable();
    setLable(lable4);

    es = expression();
    if (es > 0) return es;
    cout<<"POP"<<endl;
    fout<<"POP"<<endl;
    jumpBR(lable1);
    fin >> t;
    if (t.tokenType != ")")  return 1;
    
    setLable(lable3);
    es = statement();
    if (es > 0) return es;
    jumpBR(lable4);
    setLable(lable2);
 
    return 0;
}
int writeStat()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "write")
    {
        fin.seekg(begin);
        return -1;
    }
    int es = expression();
    if (es > 0)
    {

        return es;
    }
    fin >> t;
    if (t.tokenType != ";")
    {


        return 3;
    }
    fout<<"OUT"<<endl;
    cout<<"OUT"<<endl;
    return 0;
}
int readStat()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    string varableName;
    if (t.tokenType != "read")
    {


        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "ID")
    {

        return -1;
    }
    varableName = t.tokenValue;
    int row=t.row,col=t.column;
    fin >> t;
    if (t.tokenType != ";")
    {

        return 3;
    }
    int addr = 0;
    variabletable.LookUpVariable(varableName, addr);
    if (addr == -1)
    {
        std::cout << "[ERROR]" << "row:" << row << " col:" << col << " Undeclared variable " << varableName << std::endl;
        return 6;
    }
    fout << "IN" << endl;
    cout << "IN" << endl;
    fout << "STO " << addr << endl;
    cout << "STO " << addr << endl;
    fout << "POP" << endl;
    cout << "POP" << endl;
    return 0;
}
int declarationStat()
{
    string varableName;
    Token t;
    auto tmpPos = fin.tellg();
    fin >> t;
  
    if (t.tokenType != "int")
    {

        fin.seekg(tmpPos);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "ID")
    {

        return 2;
    }
    varableName = t.tokenValue;
    int row = t.row, col = t.column;
    fin >> t;
    if (t.tokenType != ";")
    {

        return 2;
    }
   /* if(variabletable.symbolTable.find(varableName)!= variabletable.symbolTable.end())
	{
        std::cout<<"Redeclaration of variable "<< varableName <<std::endl;
		return 4;
	}
    int siz = variabletable.symbolTable.size();
    variabletable.symbolTable[varableName] = siz;*/
    int es=variabletable.insertVariable(varableName);
    if (es == -1)
    {
        std::cout<<"[ERROR] "<<"row:"<<row<<" col:"<<col << " Redeclaration of variable " << varableName << std::endl;
		return 4;
    }
    return 0;
}
int declarationListRemoveLeftRecursivion()
{
    int es = declarationStat();
    if (es == -1)
        return 0;
    else if (es > 0)
        return es;
    es = declarationListRemoveLeftRecursivion();
    return es;
}
int declarationList()
{
    //<declaration_list>-><declaration_list><declaration_stat> | 𝜀
    //<declaration_list>->𝜀R
    // R-><declaration_stat>R | 𝜀
    int es = declarationListRemoveLeftRecursivion();
    if (es <= 0)
        return 0;
    return es;
}

int statementListRemoveLeftRecursivion()
{
    int es = statement();
    if (es == -1)
        return 0;
    else if (es > 0)
        return es;
    es = statementListRemoveLeftRecursivion();
    return es;
}
int statementList()
{
    //<statement_list>-><statement_list><statement> | 𝜀
    //<statement_list>->𝜀R
    // R-><statement>R | 𝜀
    int es = statementListRemoveLeftRecursivion();
    if (es <= 0)
        return 0;
    return es;
}

// statement_list à statement | statement statement_list