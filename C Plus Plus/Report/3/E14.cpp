#include<iostream>
#include<iomanip>
using namespace std;
void printOut(int num)
{
	cout<<setfill(' ')<<setw(10)<<setiosflags(ios::right)<<num<<endl;
}
void printOut(double num)
{
	cout<<fixed<<setprecision(4)<<num<<endl;
}
void printOut(char c)
{
	cout<<setfill(' ')<<setw(3)<<setiosflags(ios::right)<<c<<endl;	
}
int main()
{	
	cout<<"请输入一个整型数、一个浮点数、一个字符"<<endl;
	int num1;double num2;char c;
	cin>>num1>>num2>>c;
	printOut(num1);
	printOut(num2);
	printOut(c);
	return 0;
}
