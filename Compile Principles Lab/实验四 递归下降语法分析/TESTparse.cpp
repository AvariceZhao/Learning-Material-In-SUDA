#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <iostream>
#define DEBUG
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
int compoundList();
char Scanin[300] = "in.txt", Scanout[300] = "out.txt";
std::ifstream fin;
std::ofstream fout;
struct Token
{
    std::string tokenType, tokenValue;
};
std::ifstream &operator>>(std::ifstream &in, Token &token)
{
    fin >> token.tokenType >> token.tokenValue;
    std::cout << "TokenType:" << token.tokenType << " TokenValue:" << token.tokenValue << std::endl;
    return fin;
}
std::iostream &operator<<(std::iostream &out, Token &token)
{
    std::cout << "TokenType:" << token.tokenType << " TokenValue:" << token.tokenValue << std::endl;
    return out;
}
extern char Scanout[300];
FILE *fp;
// 语法分析程序
int TESTparse()
{
    int es = 0;
    fin.open(Scanin);
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
        printf(" declarationError\n");
        break;
    case 3:
        printf("Missing Semicolon Error\n");
        break;
    case 4:
        printf("\n");
        break;
    case 5:
        printf("Missing Left Parenthesis\n");
        break;
    case 6:
        printf("\n");
        break;
    case 7:
        printf("\n");
        break;
    case -1:
        printf("Terminal Symbol error\n");
    }
    fclose(fp);
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
            std::cout << "Error occur in program!\n";
            #endif 
        return 1;
    }
}

int main()
{
    int es = 0;
    if (es == 0)
    {
        es = TESTparse();
        if (es > 0)
            printf("Error occur in grammer parse,stop compile!\n");
        else
            printf("grammer parse success!\n");
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
        if(es!=-1)
        {
        #ifdef DEBUG
        std::cout << "Error occur in expressionStat!\n";
        #endif
        }
        return es;
    }
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
//<表达式> à <标识符>=<布尔表达式><布尔表达式>
//<expr> à ID=<bool _expr> | <bool_expr>
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
        }
        else
        {

            fin.seekg(begin);
            es = boolExpr();
            if (es > 0)
            {
                #ifdef DEBUG
                std::cout << "Error occur in expression!\n";
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
        if(es!=-1)
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
        return additiveExpr();
    }
    fin.seekg(tmp);
    return es;
}
int additiveExpr()
{
    int es = term();
    if (es != 0)
    {
        if(es!=-1)
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
        return term();
    fin.seekg(tmp);
    return es;
}
int term()
{
    int es = factor();
    if (es != 0)
    {
        if(es!=-1)
        {
        #ifdef DEBUG
        std::cout << "Error occur in term!\n";
        #endif
        }
        return es;
    }
    auto tmp = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType == "*" || t.tokenType == "/")
        return factor();
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
            std::cout << "Error occur in factor!\n";
            #endif
            return es;
        }
        fin >> t;
        if (t.tokenType != ")")
        {
            #ifdef DEBUG
            std::cout << "Error occur in factor!\n";
            #endif
            return 1;
        }
    }
    else if (t.tokenType == "ID")
        return 0;
    else if (t.tokenType == "NUM")
        return 0;
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
        std::cout << "Error occur in ifStat!\n";
        #endif

        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "(")
    {
        #ifdef DEBUG
        std::cout << "Error occur in ifStat!\n";
        #endif
        return 5;
    }
    int es = expression();
    if (es > 0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in ifStat!\n";
        #endif
        return es;
    }
    fin >> t;
    if (t.tokenType != ")")
    {

        #ifdef DEBUG
        std::cout << "Error occur in ifStat!\n";
        #endif

        return 1;
    }
    es = statement();
    if (es > 0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in ifStat!\n";
        #endif
        return es;
    }
    auto tmp = fin.tellg();
    fin >> t;
    if (t.tokenType == "else")
    {
        es=statement();
        if(es>0)
        {
            #ifdef DEBUG
            std::cout << "Error occur in ifStat!\n";
            #endif
            return es;
        }
        else
            return 0;
    }
    else
        fin.seekg(tmp);
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
        std::cout << "Error occur in whileStat!\n";
        #endif

        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "(")
    {
        #ifdef DEBUG
        std::cout << "Error occur in whileStat!\n";
        #endif
        return 5;
    }
    int es = expression();
    if (es > 0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in whileStat!\n";
        #endif

        return es;
    }
    fin >> t;
    if (t.tokenType != ")")
    {
        #ifdef DEBUG
        std::cout << "Error occur in whileStat!\n";
        #endif

        return 1;
    }
    es=statement();
    if(es>0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in whileStat!\n";
        #endif
        return es;
    }
    return 0;
}
int forStat()
{
    std::cout << "enter forStat\n";
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "for")
    {
        #ifdef DEBUG
        std::cout << "Error occur in forStat!\n";
        #endif
        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "(")
    {
        #ifdef DEBUG
        std::cout << "Error occur in forStat!\n";
        #endif
        return 5;
    }
    int es;
    for (int i = 0; i < 2; i++)
    {
        es = expression();
        if (es > 0)
        {
            #ifdef DEBUG
            std::cout << "Error occur in forStat!\n";
            #endif
            return es;
        }
        fin >> t;
        if (t.tokenType != ";")
        {
            #ifdef DEBUG
            std::cout << "Error occur in forStat!\n";
            #endif
            return 3;
        }
    }
    es = expression();
    if (es > 0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in forStat!\n";
        #endif

        return es;
    }
    fin >> t;
    if (t.tokenType != ")")
    {
        #ifdef DEBUG
        std::cout << "Error occur in forStat!\n";
        #endif
        return 1;
    }
    es=statement();
    if(es>0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in forStat!\n";
        #endif
        return es;
    }
    return 0;
}
int writeStat()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "write")
    {
        #ifdef DEBUG
        std::cout << "Error occur in writeStat!\n";
        #endif
        fin.seekg(begin);
        return -1;
    }
    int es = expression();
    if (es > 0)
    {
        #ifdef DEBUG
        std::cout << "Error occur in writeStat!\n";
        #endif
        return es;
    }
    fin >> t;
    if (t.tokenType != ";")
    {
        #ifdef DEBUG
        std::cout << "Error occur in writeStat!\n";
        #endif

        return 3;
    }
    return 0;
}
int readStat()
{
    auto begin = fin.tellg();
    Token t;
    fin >> t;
    if (t.tokenType != "read")
    {
        #ifdef DEBUG
        std::cout << "Error occur in readStat!\n";
        #endif

        fin.seekg(begin);
        return -1;
    }
    fin >> t;
    if (t.tokenType != "ID")
    {
        #ifdef DEBUG
        std::cout << "Error occur in readStat!\n";
        #endif
        return -1;
    }
    fin >> t;
    if (t.tokenType != ";")
    {
        #ifdef DEBUG
        std::cout << "Error occur in readStat!\n";
        #endif

        return 3;
    }
    return 0;
}
int declarationStat()
{
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
    fin >> t;
    if (t.tokenType != ";")
    {
    
        return 2;
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