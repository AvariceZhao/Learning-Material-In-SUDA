#include<bits/stdc++.h>
using namespace std;
void swap1(int x,int y)//传值调用不改变局部变量的值 
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void swap2(int *x,int *y)//指针调用可以改变局部变量的值 
{
	int temp;
	temp=*y;
	*y=*x;
	*x=temp;
}
void swap3(int &x,int &y)//引用调用能修改局部变量的值 
{
	int temp;
	temp=x;
	x=y;
	y=temp;
 } 
int sum(int num1,int num2=20)//参数的默认值 
	{
		return num1+num2;
	}
int main()
{	int a=100,b=200;
	cout<<"a="<<a<<" "<<"b="<<b<<endl;
	swap1(a,b);
	cout<<"a="<<a<<" "<<"b="<<b<<endl;
	swap2(&a,&b);
	cout<<"a="<<a<<" "<<"b="<<b<<endl;
	swap3(a,b);
	cout<<"a="<<a<<" "<<"b="<<b<<endl;
	cout<<sum(a)<<" "<<sum(a,b)<<endl; 
	return 0;
	
}
