#include <bits/stdc++.h>
#include <fstream>
using namespace std;
template <typename T>
class Array
{
    T *mArray;
    int mLen;

public:
    Array(int n);
    ~Array();
    T &operator[](int index);
};
template <typename T>
Array<T>::Array(int n)
{
      if (!n)
            this->mArray = 0;
        else
        {
            mArray = new T[n + 1];
            mLen = n;
            for (int i = 0; i <= n; i++)
                mArray[i] = T();
        }
}
template <typename T>
Array<T>::~Array()
{
    if (mArray != 0)
        delete[] mArray;
}
template <typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || index > mLen)
    {
        throw std::runtime_error("out of index");
    }
    else
    {
        return mArray[index];
    }
}

class Code
{
public:
    vector<string> code;
    bool isLable;
    Code(string s);
    Code();
};
Code::Code()
{
    code.clear();
}
Code::Code(string s)
{
    isLable = (s.back() == ':');
    if (isLable)
        s.pop_back();
    s.push_back(' ');
    string cmd = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            code.push_back(cmd);
            cmd = "";
        }
        else
        {
            cmd += s[i];
        }
    }
}
class TVM
{

public:
    TVM();
    void reset();
    int run(string path);
    int analyse();
    static const int MAXN = 1000;

private:
    int codeCounter = 0;
    Array<int> stack = Array<int>(MAXN), data = Array<int>(MAXN);
    Array<Code> code = Array<Code>(MAXN);
    unordered_map<string, int> lableJmp;
    int stackTop = 0;
};
TVM::TVM()
{
    stackTop = 0;
}
void TVM::reset()
{
    stackTop = 0;
    lableJmp.clear();
}
int TVM::run(string path)
{
    ifstream fin(path);
    string line;

    while (getline(fin, line))
    {
        if (line.back() == '\n')
            line.pop_back();
        if (line.size() == 0)
            continue;
        Code c = Code(line);
        if (c.isLable)
        {
            line.pop_back();
            lableJmp[line] = codeCounter;
            continue;
        }
        code[codeCounter++] = Code(line);
        if (code[codeCounter - 1].isLable)
        {
            line.pop_back();
            lableJmp[line] = codeCounter;
        }
    }

    int es = analyse();
    reset();
    return es;
}
int TVM::analyse()
{
    int PC = 0;
    while (PC < codeCounter)
    {

        Code &c = code[PC];

        PC++;
        vector<string> &cmd = c.code;
        if (cmd[0] == "LOAD")
        {

            stack[stackTop++] = data[stoi(cmd[1])];
        }
        else if (cmd[0] == "LOADI")
        {

            stack[stackTop++] = stoi(cmd[1]);
        }
        else if (cmd[0] == "STO")
        {

            data[stoi(cmd[1])] = stack[stackTop - 1];
        }
        else if (cmd[0] == "POP")
        {

            stackTop--;
        }
        else if (cmd[0] == "ADD")
        {

            stack[stackTop - 2] += stack[stackTop - 1];
            stackTop--;
        }
        else if (cmd[0] == "SUB")
        {

            stack[stackTop - 2] -= stack[stackTop - 1];
            stackTop--;
        }
        else if (cmd[0] == "MULT")
        {

            stack[stackTop - 2] *= stack[stackTop - 1];
            stackTop--;
        }
        else if (cmd[0] == "DIV")
        {

            stack[stackTop - 2] /= stack[stackTop - 1];
            stackTop--;
        }
        else if (cmd[0] == "BR")
        {
            PC = lableJmp[cmd[1]];
        }
        else if (cmd[0] == "BRF")
        {
            if (stack[--stackTop] == 0)
            {
                PC = lableJmp[cmd[1]];
            }
            else
            {
            }
        }
        else if (cmd[0] == "EQ")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] == stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "NOTEQ")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] != stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "GT")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] > stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "LES")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] < stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "GE")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] >= stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "LE")
        {

            stack[stackTop - 2] = (stack[stackTop - 2] <= stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "AND")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] && stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "OR")
        {
            stack[stackTop - 2] = (stack[stackTop - 2] || stack[stackTop - 1]);
            stackTop--;
        }
        else if (cmd[0] == "NOT")
        {
            stack[stackTop - 1] = !stack[stackTop - 1];
        }
        else if (cmd[0] == "IN")
        {
            int x;
            cin >> x;
            stack[stackTop++] = x;
        }
        else if (cmd[0] == "OUT")
        {
            cout << stack[--stackTop] << endl;
        }
        else if (cmd[0] == "STOP")
        {
            return 0;
        }
        else
        {
            cout << "ERROR: " << cmd[0] << endl;
            return 1;
        }
    }
    return 0;
}
int main()
{
    // Array<int> array1(TVM::MAXN);
    TVM TVM;
    TVM.run("b.asm");
}