#include<bits/stdc++.h>
using namespace std;
void swap1(int x,int y)//��ֵ���ò��ı�ֲ�������ֵ 
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void swap2(int *x,int *y)//ָ����ÿ��Ըı�ֲ�������ֵ 
{
	int temp;
	temp=*y;
	*y=*x;
	*x=temp;
}
void swap3(int &x,int &y)//���õ������޸ľֲ�������ֵ 
{
	int temp;
	temp=x;
	x=y;
	y=temp;
 } 
int sum(int num1,int num2=20)//������Ĭ��ֵ 
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
