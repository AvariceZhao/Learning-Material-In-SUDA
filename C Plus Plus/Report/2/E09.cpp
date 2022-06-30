#include<iostream>
using namespace std;
int main()
{	int cnt=0;
	for(int i=0;i<=20;i++)
		for(int j=0;j<=33;j++)
				{
					int num=100-i-j,money=100-5*i-3*j;
					if(num/3==money&&num%3==0)
					cout<<"鸡翁:"<<i<<"	鸡母:"<<j<<"	鸡雏:"<<num<<endl;
				}
	return 0;
}
