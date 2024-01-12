#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Lexer
{
private:
    std::string keywords[10] = {"if", "else", "for", "while", "do", "int", "read", "write"};
    const std::string singleSymbols = "+-*(){};,:";
    const std::string doubleSymbols = "><=!";

    std::ifstream inputFile;
    std::ofstream outputFile;
    int line;
    int col;
    char ch;
    bool inComment;

public:
    Lexer(const std::string &inputFileName, const std::string &outputFileName) : line(1), col(1)
    {
        inputFile.open(inputFileName);
        inputFile.unsetf(std::ios_base::skipws);
        outputFile.open(outputFileName);
        ch = char();
    }

    ~Lexer()
    {
        inputFile.close();
        outputFile.close();
    }

    int run()// 0:正常结束  1:有问题  2：继续读
    {
        inputFile.get(ch);
        while (1)
        {

            if (ch == EOF)
                return 0;

            if (std::isspace(ch))
            {
                int ret = handleWhitespace();

                if(ret==0)
                    return 0;
                else if (ret==1)
                    return 1;
                

            }
            else if (std::isalpha(ch))
            {
                int ret = handleIdentifier();
                if(ret==0)
                    return 0;
                else if (ret==1)
                    return 1;
            }
            else if (std::isdigit(ch))
            {
                int ret = handleNumber();
                if(ret==0)
                    return 0;
                else if (ret==1)
                    return 1;
            }
            else if (singleSymbols.find(ch) != std::string::npos)
            {
            
             int ret = handleSingleSymbol();
                if(ret==0)
                    return 0;
                else if (ret==1)
                    return 1;
            }
            else if (doubleSymbols.find(ch) != std::string::npos)
            {
                int ret = handleDoubleSymbol();
                if(ret==0)
                    return 0;
                else if (ret==1)
                    return 1;

            }
            else if (ch == '/')
            {
                int ret = handleComment();
                if(ret==0)
                    return 0;
                else if (ret==1)
                    return 1;
            }
            else
            {
                handleInvalidToken();
                return 1;
            }
        }
    }

private:
// 0:正常结束  1:有问题  2：继续读
    int handleWhitespace()
    {
        if (ch == '\n')
        {
            line++;
            col = 0;
        }
        col++;
        if (!inputFile.get(ch))
        {
            if(inComment)
            {
                outputFile << "[Error] Unclosed comment" << "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
            return 0;
        }

        return 2;
    }

    int handleIdentifier()
    {
       
        std::string temp;

        while (std::isalnum(ch))
        {
            temp.push_back(ch);
            col++;
            
            if (!inputFile.get(ch))
            {
            
            handleID(temp);
            if(inComment)
            {
                outputFile << "[Error] Unclosed comment" << "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
                
                return 0;
            }
        }
        

        handleID(temp);

        return 2;
    }

    int handleNumber() 
    {
      
        std::string temp;

        while (std::isdigit(ch))
        {
            temp.push_back(ch);
            if (!inputFile.get(ch))
            {
            if(inComment)
            {
                 outputFile << "NUM " << temp << "\n";
                outputFile << "[Error] Unclosed comment" << "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
                
                return 0;
            }
            col++;
        }
      
        if (!isdigit(ch))
        {
            if (ch == ';')
            { 
            outputFile << "NUM " << temp << "\n";
            return 2;
            }
            else
            {
              outputFile << "[Error] Invalid token! line:" << line << " col:" << col << "\n";
              std::cout<< "[Error] Invalid token! line:" << line << " col:" << col << "\n";
              return 1;
            }
        }

        return 2;
    }

    int handleSingleSymbol()
    {
        char pre = ch;
        outputFile << ch << " " << ch << "\n";
  
        if (!inputFile.get(ch))
        {
            if(inComment)
            {
                outputFile << "[Error] Unclosed comment"<< "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
            return 0;

        }
        else
        {   if(pre=='*'&&ch=='/')
               {
                outputFile <<"[Error] Redundant right comment."<< line << " col:" << col << "\n";
                std::cout<<"[Error] Redundant right comment."<< line << " col:" << col << "\n";
                return 1;
                }
            return 2;
        }
    }

    int handleDoubleSymbol()
    {
        char pre, nxt;
        pre = ch;
        if (!inputFile.get(nxt))
        {
            if(inComment)
            {
                outputFile << "[Error] Unclosed comment" <<  "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
            outputFile << pre << " " << pre << "\n";
            return 0;
        }
        col++;

        if (doubleSymbols.find(nxt) != std::string::npos)
        {
            outputFile << pre << nxt << " " << pre << nxt << "\n";
        
            if (!inputFile.get(ch))
            {

                outputFile << "[Error] Invalid token! line:" << line << " col:" << col << "\n";
                std::cout<< "[Error] Invalid token! line:" << line << " col:" << col << "\n";
                return 1;
            }
            else
            {
                
                return 2;
            }
        }
        else
        {
            outputFile << pre << " " << pre << "\n";
            ch = nxt;
            return 2;
        }
        return 2;
    }

    int handleComment()
    {
        
        char pre, nxt;
        pre = ch;
        if (!inputFile.get(nxt))
        {
            outputFile << "/ /\n";
            return 0;
        }
        col++;
        if (nxt == '*')
        {
            inComment = 1;
            if (!inputFile.get(pre))
            {
                         outputFile << "[Error] Unclosed comment" <<  "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
            col++;

            while (inputFile.get(nxt))
            {
                if(nxt=='\n')
                {
                    line++;
                    col = 0;
                }
                else
                {
                    col++;
                }
                if (pre == '*' && nxt == '/')
                    {
                    inComment = 0;
                    break;
                    }
                pre = nxt;
            }

            if(!inputFile.get(ch))
            {
            
            if(inComment)
            {
              outputFile << "[Error] Unclosed comment" <<  "\n";
                std::cout<< "[Error] Unclosed comment" << "\n";
                return 1;
            }
                return 0;
            } 
            else
            {
                return 2;
            }  
        }
        else
        {
            outputFile << pre << " " << pre << "\n";
            ch = nxt;
            return 2;
        }

        return 2;
    }

    int handleInvalidToken()
    {
        outputFile << "[Error] Invalid token! line:" << line << " col:" << col << "\n";
        std::cout<<"[Error] Invalid token! line:" << line << " col:" << col << "\n";
        return 1;
    }

    void handleID(std::string temp)
    {
         std::string id = temp;

        for(auto &i:id)
        {
                if (i >= 'A' && i <= 'Z')
                i += 'a' - 'A';

        }

        for (auto i : keywords)
        {
            if (id == i)
            {
                outputFile << i << " " << i << "\n";
                return;
            }
        }

          outputFile << "ID " << temp << "\n";
    }
};

int main()
{
   
    Lexer lexer("AAA.txt", "AAA1.out");
    if(lexer.run())
        std::cout << "Error!\n";
    else
        std::cout << "Completed!\n";

    return 0;
}
