#include<bits/stdc++.h>
//:: �����������ַ���ָ��һ�����������ĸ����һ�����������ĸ��ࡣ
//:: ���Բ�����������ʾȫ�����ݻ�ȫ�ֺ��������ǳ�Ա��������
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
void box::set(double len,double bre,double hei)//�������ڲ�ֱ�Ӷ��庯����Ҳ�������ⲿ�÷�Χ������������庯��(::) ��::ǰ������� 
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
	int va=a.breadth*a.height*a.length;//˽�г�Ա������.������ 
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
