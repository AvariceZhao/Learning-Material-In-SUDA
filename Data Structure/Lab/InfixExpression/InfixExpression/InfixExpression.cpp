
#include "InfixExpression.h"

bool InfixExpression::detail = false; 


void InfixExpression::showDetail(bool choice)
{
    InfixExpression::detail = choice;
}


InfixExpression::InfixExpression(string str) //除去表达式里的空格
{
    (*this).expression = str;
    auto p = expression.begin();
    while (p != expression.end())
    {
        if (*p == ' ' || *p == '#')p = expression.erase(p);
        else ++p;
    }
}




double InfixExpression::calculateExpression() 
{
    //清除上一次的计算结果
    operands.clear();
    operators.clear();

    //输出细节

    if (detail)
    {
        cout << "Checking the bracket matching of the expression..." << endl;
    }
    
    //判断括号匹配
    checkBracketMatch(expression);

 
    //输出细节
    if (detail)
    {
        cout << "Parsing the expression..." << endl;

    }

    //将表达式解析用空格分离每一段，并将结果存储到字符串流中，用于存储
    stringstream source(parseExpression(expression));

    if (detail)
    {
        cout << "Parsed the expression successfully! The parsed expression is :" << source.str() << endl;
    }


    string nextString;
    //开始处理表达式分解后的每一段
    while (source >> nextString)
    {
        if (detail)
            cout << "Get " << nextString << " from the expression" << endl;

        if (judgeDigitString(nextString))//如果这一部分是数字
        {
            char* temp;
            saveOperand(strtod(nextString.c_str(), &temp));//将数字字符串转为double并压入操作数栈
            continue;
        }

        char op = nextString[0];//取出这一部分
        if (op == ')') //如果是右括号，则说明需要进行运算了
        {
            if (detail) { cout << "The sub expression in brackets will be calculated in advance." << endl; }

            while (!operators.empty() && operators.top() != '(') 
            { 
                stepCalculate(); //运算一次
            }

            getOperator(op);  // 弹出左括号
            if (detail) { cout << "The calculation of sub expression finished." << endl; }
            continue;
        }
        if (!operators.empty() && compareOperators(operators.top(), op) > 0) //如果优先级可以运算
        {
            stepCalculate(); //进行一次运算
        }
        saveOperator(op);//存储这个操作符
    }

    //计算剩余部分
    if (detail) 
    {
        cout << "The expression ends" << endl; 
    }

    while (!operators.empty()) { stepCalculate(); }

    
    return getResult();
}

inline void InfixExpression::stepCalculate()
{
    char op;
    double left, right;

    getOperator(op);//取出栈顶操作符
    getOperands(left, right);//取出两个操作数

    saveOperand(digitCompute(left, op, right));//运算一次并将结果存入操作数栈

}

inline void InfixExpression::getOperands(double& left, double& right)
{
    try
    {
        right = operands.top(); operands.pop();//取出两个操作数
        if (detail) { cout << "<< Right operand " << right << " pop out of the operands stack." << endl; }
        left = operands.top(); operands.pop();
        if (detail) { cout << "<< Left operand " << left << " pop out of the operands stack." << endl; }
    }
    catch (underflow_error) //栈空则报错
    {
        throw  runtime_error{ "[Underflow_error] Invalid expression is given: mising operand(s) When popping operands" };
    }
}

inline void InfixExpression::saveOperand(double result)
{
    //存储操作数
    try
    {
        operands.push(result);
        if (detail) { cout << ">> Push number " << result << " into the operands stack." << endl; }

    }
    catch (overflow_error(&e))
    {
        throw  runtime_error{ string("[Overflow_error] The expression too long, operands , When saving operands") + e.what() };
    }
}

inline char& InfixExpression::getOperator(char& op)
{
    //获得操作符
    try
    {
        op = operators.top();
        operators.pop();

        if (detail)
        {
            cout << "<< Operator '" << op << "' pop out of operators stack." << endl;
        }
    }
    catch (underflow_error&)//如果栈空则报错
    {
        throw  runtime_error{ "[Runtime_error],Invalid expression is given:mising operator(s),When popping an operator" };

    }
    //返回取得的操作符
    return op;

}

inline void InfixExpression::saveOperator(char op)
{
    //存储操作符
    if (!(op == '+' || op == '~' || op == '*' || op == '/' || op == '('))
    {
        throw  runtime_error{ "[Runtime_error] Invalid operator is given When Pushing the operator" };

    }
    try {
        operators.push(op);
        if (detail) { cout << "<< Push operator '" << op << " 'into opertors stack" << endl; }
    }
    catch (overflow_error& e)
    {
        throw  runtime_error{ string("[Overflow_error] The expression too long, operators ") + e.what() };
    }
}

inline double InfixExpression::getResult()
{

    //返回结果
    double result;
    try
    {
        result = operands.top(); operands.pop();
    }
    catch (underflow_error&)
    {
        throw  runtime_error{ "[Runtime_error] Invalid expression is given,missing operand(s) ,When getting result" };
    }
    if (!operands.empty())//如果弹出栈顶后栈中还有元素则抛出错误
    {
        if (detail)
        {
            cout << "Fail to get the result ! there are 2 or more operand(s) in the operands stack:" << result;
            while (!operands.empty()) { cout << ", " << operands.top(); operands.pop(); }
            cout << endl;
        }
        throw  runtime_error{ "[Runtime_error] Invalid expression is given: missing operator(s),When getting result" };
    }
    if (detail) { cout << "<< Get the result " << result << " from the operands stack" << endl; }
    return result;
}

void InfixExpression::checkBracketMatch(const  string& expression)
{
    Stack<char>stack;
    for (char p : expression)
    {
        if (p == '(')//如果是左括号则入栈
        {
            stack.push(p);
            continue;
        }
        if (p == ')' && (stack.empty() || stack.pop() != '('))//如果右括号无法匹配则报错
        {
            throw  runtime_error
            {
                "[Runtime_error] Invalid bracket matches of the expression : missing '(' When checking the bracket matching of the expression"
            };
        }
    }
    //如果左括号有剩余的报错
    if (!stack.empty())
        throw  runtime_error{
        "[Runtime_error] Invalid bracket matches of the expression :missing ') When checking the bracket matching of the expression"
    };
}
string InfixExpression::parseExpression(const  string& expression)//解析表达式
{
    string temp_expression(expression);//存储表达式解析后的临时结果
    for (int i = 0; i < temp_expression.length(); i++)
    {
        if (!judgeValidChar(temp_expression[i]))//如果出现非法字符则直接抛出错误
        {
            throw  runtime_error{ "[Runtime_error] Invalid expression is given : Expression containing invalid character When parsing the expression" };

        }
        judgeMinus(temp_expression, i);//由于-有两种含义：减号和负号，所以需要进行区分，这里把减号统一转换为~表示，-表示负号
    }

    splitOperatorsOperands(temp_expression);
    return temp_expression;
}

int InfixExpression::compareOperators(char op1, char op2)  {
    
    switch (op1) 
    {
    case '(':   return -1;
    case '*':  
    case '/': if (op2 == '(')  return -1;
        return 1;
    case '+':  
    case '~': 
        if (op2 == '+' || op2 == '~') return 1;
        return -1;
    }
    exit(1);
}

double InfixExpression::digitCompute(double l, char op, double r)
{
    //进行运算并返回结果
    if (op == '+')return l + r;
    else if (op == '~')return l - r;
    else if (op == '*')return l * r;
    else if (op == '/')
    {
        if (r == 0)//除0则报错
        {
            throw runtime_error{ "[Runtime_error] Division by 0 error When computing" };

        }
        return l / r;
    }
    return 0;
}

bool InfixExpression::judgeDigitString(const  string& str)//判断是否为数字字符串
{
    for (char ch : str)//如果字符串中全为数字或小数点或负号则为
    {
        if (!(ch == '-' || ch == '.' || isdigit(ch)))
            return false;
    }
    return true;
}
void InfixExpression::splitOperatorsOperands(string& expression)
{
    //把操作符和数字分离开来
    char ops[6] = { '+', '~', '*', '/' ,'(',')' };
    for (auto op : ops)
    {
        auto pos = expression.find(op);
        //把所有操作符替换为空格+操作符+空格

        while (pos != string::npos)
        {
            expression = expression.replace(pos, 1, { ' ',op,' ' });//替换
            pos = expression.find(op, pos + 2);//继续替换后面的内容
        }

    }
}
bool InfixExpression::judgeValidChar(char ch)//用于判断表达式中是否出现非法字符
{
    string validString = "0123456789+-*/().";
    if (validString.find(ch) == string::npos)
        return false;
    return true;
}

void InfixExpression::judgeMinus(string& expression, int pos)
{
    if (pos != 0 && pos != expression.length() - 1 && expression[pos] == '-')
    {
        if (expression[pos - 1] == ')' || isdigit(expression[pos - 1]) || !isdigit(expression[pos + 1]))//如果-出现在右括号后或者数字后或者后一位是非数字，则-只能表示减号
        {
            expression[pos] = '~';//把-转为~表示减号
        }
    }

    if (pos == 0 && expression[pos] == '-' && !isdigit(expression[pos + 1])) //下一位不是数字则表示减号
    {
        expression[pos] = '~';
    }
    if (pos == expression.length() - 1 && expression[pos] == '-') //最后一位只能表示减号
    {
        expression[pos] = '~';
    }

}
