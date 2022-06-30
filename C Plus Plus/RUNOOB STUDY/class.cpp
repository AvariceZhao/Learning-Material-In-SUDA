#include<bits/stdc++.h>
//:: 叫作用域区分符，指明一个函数属于哪个类或一个数据属于哪个类。
//:: 可以不跟类名，表示全局数据或全局函数（即非成员函数）。
using namespace std;
class box{
	public:
		double length;
		double breadth;
		double height;
		double width;
		double getv(); 
		double getwidth();
		void set(double len,double bre,double hei); 
	private:
		double statics;	
};
double box::getv(){
	return length*breadth*height;
}
void box::set(double len,double bre,double hei)//可以在内部直接定义函数，也可以在外部用范围解析运算符定义函数(::) 在::前必须加上 
{
	length=len;
	breadth=bre;
	height=hei;
}
double box::getwidth()
{
	return width;
}
void box::setwidth(double wid)
{
	width=wid;
}
int main()
{	box a,b;
	a.breadth=3.0;
	a.height=4.0;
	a.length=5.0;
	b.breadth=1.0;
	b.height=2.0;
	b.length=3.0;
	int va=a.breadth*a.height*a.length;//私有成员不能用.来访问 
	int vb=b.breadth*b.height*b.length;
	cout<<va<<endl;
	cout<<vb<<endl;
	a.set(10,10,10) ;
	b.set(1,1,1);
	va=a.breadth*a.height*a.length;
	vb=b.breadth*b.height*b.length;
	cout<<va<<endl;
	cout<<vb<<endl;
 } 
