#include<iostream>
using namespace std;
void reverseNum()
{
	int n,x=0;
	cout<<"请输入待对调的数字:";
	cin>>n;
	while(n)
	{	
		x*=10;
		x+=n%10;
		n/=10;
	}
	cout<<x<<endl;
}
int main()
{
	reverseNum();
	return 0;
}
