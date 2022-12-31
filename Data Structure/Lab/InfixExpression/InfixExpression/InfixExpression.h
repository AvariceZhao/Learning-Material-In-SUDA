#pragma once
#include"utility.h"
#include"LinkStack.hpp"
class InfixExpression
{
public:

	static void showDetail(bool = false);
	explicit InfixExpression(string);
	double calculateExpression();//计算

private:

	string expression;//表达式
	Stack<char>operators;//操作符栈
	Stack<double>operands;//操作数栈

	static bool detail;//显示细节选项



	void getOperands(double&, double&);//获得一对操作数
	void saveOperand(double);//保存操作数
	char& getOperator(char&);//获得操作符
	void saveOperator(char);//保存操作符

	void stepCalculate();//单步计算并保存
	double digitCompute(double, char, double);//数字计算
	double getResult();//获得最终运算结果


	void checkBracketMatch(const string&);//判断括号匹配
	void splitOperatorsOperands(string&);//分离操作符和操作数
	string parseExpression(const string&);//解析表达式


	
	bool judgeDigitString(const string&);//判断是否是数字串
	bool judgeValidChar(char ch);//判断是否为合法字符
	void judgeMinus(string&, int);//判断并修改减号和负号
	int compareOperators(char, char);//比较两操作符的优先级
};