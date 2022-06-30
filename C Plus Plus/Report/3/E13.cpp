#include<iostream>
#include<cmath>
using namespace std;
int gcd,lcm,num1,num2;
void calc(int num1,int num2)
{
	for(int i=1;i<=min(num1,num2);i++)
	{
		if(num1%i==0&&num2%i==0)
		{
			gcd=i;
		}
	}
	lcm=num1*num2/gcd;
}
int main()
{	
	cout<<"请输入两个整数:";
	cin>>num1>>num2;
	calc(num1,num2);
	cout<<"最大公约数:"<<gcd<<endl<<"最小公倍数:"<<lcm<<endl;
	return 0;
}
