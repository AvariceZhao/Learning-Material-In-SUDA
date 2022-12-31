
#include "InfixExpression.h"

bool InfixExpression::detail = false; 


void InfixExpression::showDetail(bool choice)
{
    InfixExpression::detail = choice;
}


InfixExpression::InfixExpression(string str) //��ȥ���ʽ��Ŀո�
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
    //�����һ�εļ�����
    operands.clear();
    operators.clear();

    //���ϸ��

    if (detail)
    {
        cout << "Checking the bracket matching of the expression..." << endl;
    }
    
    //�ж�����ƥ��
    checkBracketMatch(expression);

 
    //���ϸ��
    if (detail)
    {
        cout << "Parsing the expression..." << endl;

    }

    //�����ʽ�����ÿո����ÿһ�Σ���������洢���ַ������У����ڴ洢
    stringstream source(parseExpression(expression));

    if (detail)
    {
        cout << "Parsed the expression successfully! The parsed expression is :" << source.str() << endl;
    }


    string nextString;
    //��ʼ������ʽ�ֽ���ÿһ��
    while (source >> nextString)
    {
        if (detail)
            cout << "Get " << nextString << " from the expression" << endl;

        if (judgeDigitString(nextString))//�����һ����������
        {
            char* temp;
            saveOperand(strtod(nextString.c_str(), &temp));//�������ַ���תΪdouble��ѹ�������ջ
            continue;
        }

        char op = nextString[0];//ȡ����һ����
        if (op == ')') //����������ţ���˵����Ҫ����������
        {
            if (detail) { cout << "The sub expression in brackets will be calculated in advance." << endl; }

            while (!operators.empty() && operators.top() != '(') 
            { 
                stepCalculate(); //����һ��
            }

            getOperator(op);  // ����������
            if (detail) { cout << "The calculation of sub expression finished." << endl; }
            continue;
        }
        if (!operators.empty() && compareOperators(operators.top(), op) > 0) //������ȼ���������
        {
            stepCalculate(); //����һ������
        }
        saveOperator(op);//�洢���������
    }

    //����ʣ�ಿ��
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

    getOperator(op);//ȡ��ջ��������
    getOperands(left, right);//ȡ������������

    saveOperand(digitCompute(left, op, right));//����һ�β���������������ջ

}

inline void InfixExpression::getOperands(double& left, double& right)
{
    try
    {
        right = operands.top(); operands.pop();//ȡ������������
        if (detail) { cout << "<< Right operand " << right << " pop out of the operands stack." << endl; }
        left = operands.top(); operands.pop();
        if (detail) { cout << "<< Left operand " << left << " pop out of the operands stack." << endl; }
    }
    catch (underflow_error) //ջ���򱨴�
    {
        throw  runtime_error{ "[Underflow_error] Invalid expression is given: mising operand(s) When popping operands" };
    }
}

inline void InfixExpression::saveOperand(double result)
{
    //�洢������
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
    //��ò�����
    try
    {
        op = operators.top();
        operators.pop();

        if (detail)
        {
            cout << "<< Operator '" << op << "' pop out of operators stack." << endl;
        }
    }
    catch (underflow_error&)//���ջ���򱨴�
    {
        throw  runtime_error{ "[Runtime_error],Invalid expression is given:mising operator(s),When popping an operator" };

    }
    //����ȡ�õĲ�����
    return op;

}

inline void InfixExpression::saveOperator(char op)
{
    //�洢������
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

    //���ؽ��
    double result;
    try
    {
        result = operands.top(); operands.pop();
    }
    catch (underflow_error&)
    {
        throw  runtime_error{ "[Runtime_error] Invalid expression is given,missing operand(s) ,When getting result" };
    }
    if (!operands.empty())//�������ջ����ջ�л���Ԫ�����׳�����
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
        if (p == '(')//���������������ջ
        {
            stack.push(p);
            continue;
        }
        if (p == ')' && (stack.empty() || stack.pop() != '('))//����������޷�ƥ���򱨴�
        {
            throw  runtime_error
            {
                "[Runtime_error] Invalid bracket matches of the expression : missing '(' When checking the bracket matching of the expression"
            };
        }
    }
    //�����������ʣ��ı���
    if (!stack.empty())
        throw  runtime_error{
        "[Runtime_error] Invalid bracket matches of the expression :missing ') When checking the bracket matching of the expression"
    };
}
string InfixExpression::parseExpression(const  string& expression)//�������ʽ
{
    string temp_expression(expression);//�洢���ʽ���������ʱ���
    for (int i = 0; i < temp_expression.length(); i++)
    {
        if (!judgeValidChar(temp_expression[i]))//������ַǷ��ַ���ֱ���׳�����
        {
            throw  runtime_error{ "[Runtime_error] Invalid expression is given : Expression containing invalid character When parsing the expression" };

        }
        judgeMinus(temp_expression, i);//����-�����ֺ��壺���ź͸��ţ�������Ҫ�������֣�����Ѽ���ͳһת��Ϊ~��ʾ��-��ʾ����
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
    //�������㲢���ؽ��
    if (op == '+')return l + r;
    else if (op == '~')return l - r;
    else if (op == '*')return l * r;
    else if (op == '/')
    {
        if (r == 0)//��0�򱨴�
        {
            throw runtime_error{ "[Runtime_error] Division by 0 error When computing" };

        }
        return l / r;
    }
    return 0;
}

bool InfixExpression::judgeDigitString(const  string& str)//�ж��Ƿ�Ϊ�����ַ���
{
    for (char ch : str)//����ַ�����ȫΪ���ֻ�С����򸺺���Ϊ
    {
        if (!(ch == '-' || ch == '.' || isdigit(ch)))
            return false;
    }
    return true;
}
void InfixExpression::splitOperatorsOperands(string& expression)
{
    //�Ѳ����������ַ��뿪��
    char ops[6] = { '+', '~', '*', '/' ,'(',')' };
    for (auto op : ops)
    {
        auto pos = expression.find(op);
        //�����в������滻Ϊ�ո�+������+�ո�

        while (pos != string::npos)
        {
            expression = expression.replace(pos, 1, { ' ',op,' ' });//�滻
            pos = expression.find(op, pos + 2);//�����滻���������
        }

    }
}
bool InfixExpression::judgeValidChar(char ch)//�����жϱ��ʽ���Ƿ���ַǷ��ַ�
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
        if (expression[pos - 1] == ')' || isdigit(expression[pos - 1]) || !isdigit(expression[pos + 1]))//���-�����������ź�������ֺ���ߺ�һλ�Ƿ����֣���-ֻ�ܱ�ʾ����
        {
            expression[pos] = '~';//��-תΪ~��ʾ����
        }
    }

    if (pos == 0 && expression[pos] == '-' && !isdigit(expression[pos + 1])) //��һλ�����������ʾ����
    {
        expression[pos] = '~';
    }
    if (pos == expression.length() - 1 && expression[pos] == '-') //���һλֻ�ܱ�ʾ����
    {
        expression[pos] = '~';
    }

}
