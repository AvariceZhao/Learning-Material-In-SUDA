#pragma once
#include"utility.h"
#include"LinkStack.hpp"
class InfixExpression
{
public:

	static void showDetail(bool = false);
	explicit InfixExpression(string);
	double calculateExpression();//����

private:

	string expression;//���ʽ
	Stack<char>operators;//������ջ
	Stack<double>operands;//������ջ

	static bool detail;//��ʾϸ��ѡ��



	void getOperands(double&, double&);//���һ�Բ�����
	void saveOperand(double);//���������
	char& getOperator(char&);//��ò�����
	void saveOperator(char);//���������

	void stepCalculate();//�������㲢����
	double digitCompute(double, char, double);//���ּ���
	double getResult();//�������������


	void checkBracketMatch(const string&);//�ж�����ƥ��
	void splitOperatorsOperands(string&);//����������Ͳ�����
	string parseExpression(const string&);//�������ʽ


	
	bool judgeDigitString(const string&);//�ж��Ƿ������ִ�
	bool judgeValidChar(char ch);//�ж��Ƿ�Ϊ�Ϸ��ַ�
	void judgeMinus(string&, int);//�жϲ��޸ļ��ź͸���
	int compareOperators(char, char);//�Ƚ��������������ȼ�
};