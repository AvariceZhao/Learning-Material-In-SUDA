#include<iostream>
using namespace std;
int main()
{
	int h,r,n;
	cin>>h>>r;
	n=20000/((3.14159*r*r)*h)+1;
	cout<<n;
	return 0;
}