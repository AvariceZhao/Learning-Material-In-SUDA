#include "InfixExpression.h"
int main()
{
    string line, detail;
    cout << "Whether to show the detail ?（Y/N）" << endl;
    cin >> detail;
    if (detail[0] == 'Y' || detail[0] == 'y')
        InfixExpression::showDetail(1);
    else
        InfixExpression::showDetail(0);
    cout << "Input the expression:";
    while (getline(cin,line))
    {
        if (cin.eof() || line == "exit")
            return 0;
        if (line.empty()) {
            continue;
        }
           InfixExpression expression(line);
        try 
        {
            cout << expression.calculateExpression() << endl;
        }
        catch (runtime_error& e)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "Unexpected line in <stdin> : " << line << endl<< e.what() << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        cout << "-------------------------------------------------------------" << endl;
        cout << "Input the expression:";
    }
  
   }



