#include<bits/stdc++.h>
using namespace std;
void f(int arr[])//形参为未定义大小的数组 
{
	cout<<arr[1];
}
//void f2(int *p)形参为指针
//void f3(int a[5)形参为指定大小的数组 
int main()
{	int a[5][5][5];//多维数组 
	cout<<setfill('*')<<setw(4)<<"1"<<endl;//4表示宽度，setw对接下来输出的内容起作用，默认填充内容为空格，可用setwfill()控制 
	int b[5]={1,2,3,4,5};
	int *p;
	p=b;
	cout<<"使用指针的数组值："<<endl;
	for(int i=0;i<5;i++) 
	{
		cout<<"(*p+"<<i<<")=";
		cout<<*(p+i)<<endl;
	}
	cout<<"使用b作为地址的数组值："<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"*(b+"<<i<<")=";
		cout<<*(b+i)<<endl;
	}
	f(b);
	return 0;
 } 
