#include<iostream>
using namespace std;
void reverseNum()
{
	int n,x=0;
	cout<<"��������Ե�������:";
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
