#include<bits/stdc++.h>
using namespace std;
void f(int arr[])//�β�Ϊδ�����С������ 
{
	cout<<arr[1];
}
//void f2(int *p)�β�Ϊָ��
//void f3(int a[5)�β�Ϊָ����С������ 
int main()
{	int a[5][5][5];//��ά���� 
	cout<<setfill('*')<<setw(4)<<"1"<<endl;//4��ʾ��ȣ�setw�Խ�������������������ã�Ĭ���������Ϊ�ո񣬿���setwfill()���� 
	int b[5]={1,2,3,4,5};
	int *p;
	p=b;
	cout<<"ʹ��ָ�������ֵ��"<<endl;
	for(int i=0;i<5;i++) 
	{
		cout<<"(*p+"<<i<<")=";
		cout<<*(p+i)<<endl;
	}
	cout<<"ʹ��b��Ϊ��ַ������ֵ��"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"*(b+"<<i<<")=";
		cout<<*(b+i)<<endl;
	}
	f(b);
	return 0;
 } 
