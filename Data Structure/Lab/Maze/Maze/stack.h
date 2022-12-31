#pragma once
template<typename T1>
class stack
{
private:
	T1 stk[10000];
	int Bottom = 0;
	int Top = -1;
public:
	void push(T1 u)
	{
		stk[++Top] = u;
	}
	void pop()
	{
		Top--;
	}
	bool empty()
	{
		return Top < Bottom;
	}
	T1 top()
	{
		return stk[Top];
	}

};