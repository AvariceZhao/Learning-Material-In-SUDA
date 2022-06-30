#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A=60;
	int B=13;
	int c=A&B;//与 
	cout<<c<<endl;
	c=A|B;//或 
	c=A^B;//异或 
	c=A~B;//取反 
	c=A<<2;//左移 
	c=A>>2; //右移 正数补0负数补1 
	//可以<<= >>= &=  ^=  |=
	return 0;
 } 
