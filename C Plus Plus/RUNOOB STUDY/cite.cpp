#include<bits/stdc++.h>
using namespace std;
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
//���ö����ں������ݲ��� ����ͨ���������β�ָ��ʵ�����ı�ʵ�ε�ֵ�����ָ����Ӱ�ȫ 
void swap1(int& a,int& b)//�������� 
{	int temp=a;
	a=b;
	b=temp;
	
	
 } 
 double& setValues(int i) {  
   double& ref = vals[i];    
   return ref;   // ���ص� i ��Ԫ�ص����ã�ref ��һ�����ñ�����ref ���� vals[i],�����÷��غ���ֵ����Ҫ�ں�����ǰ����& 
 
 
}
int main()
{	int i=17;
	int j=16;
	int&q =j;
	double d;
	int& r=i;//���ñ���������ʱ����ʼ��
	double& s=d;
	d=11.3;
	cout<<r<<endl<<s<<endl; 
	cout<<j<<" "<<r<<endl;
	swap1(j,r);
	cout<<j<<" "<<r;
	cout<<"_______________________________________________________________________________________";
	 cout <<endl<< "�ı�ǰ��ֵ" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   setValues(1) = 20.23; // �ı�� 2 ��Ԫ��
   setValues(3) = 70.8;  // �ı�� 4 ��Ԫ��
 
   cout << "�ı���ֵ" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   } 
	return 0;
}
