#include<bits/stdc++.h>
using namespace std;
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
//引用多用于函数传递参数 可以通过将引用形参指向实参来改变实参的值，相比指针更加安全 
void swap1(int& a,int& b)//利用引用 
{	int temp=a;
	a=b;
	b=temp;
	
	
 } 
 double& setValues(int i) {  
   double& ref = vals[i];    
   return ref;   // 返回第 i 个元素的引用，ref 是一个引用变量，ref 引用 vals[i],以引用返回函数值，需要在函数名前加上& 
 
 
}
int main()
{	int i=17;
	int j=16;
	int&q =j;
	double d;
	int& r=i;//引用必须在声明时被初始化
	double& s=d;
	d=11.3;
	cout<<r<<endl<<s<<endl; 
	cout<<j<<" "<<r<<endl;
	swap1(j,r);
	cout<<j<<" "<<r;
	cout<<"_______________________________________________________________________________________";
	 cout <<endl<< "改变前的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   setValues(1) = 20.23; // 改变第 2 个元素
   setValues(3) = 70.8;  // 改变第 4 个元素
 
   cout << "改变后的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   } 
	return 0;
}
