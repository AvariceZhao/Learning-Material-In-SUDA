#include<bits/stdc++.h>
using namespace std;
class line{
	public:
	void setlen(double len);
	double getlen();
	line();//无参数构造函数
	private:
	double length; 
};
class box{
	public:
		double getv();
		void setsize(double a,double b,double c);
		box(string name);//含参数的构造函数 
	private:
		double l;
		double w;
		double h;
		string name;
		double v;
		
};
double box::getv()
{
	return v;
}
void box::setsize(double a,double b,double c)
{
	l=a;
	w=b;
	h=c;
	v=a*b*c;
}
box::box(string name1)
{	cout<<"name your box";
	cin>>name1;
	name=name1;
	cout<<"Your box has been named"<<endl;	
}
line::line()
{	
	cout<<"Object is being created";
}
void line::setlen(double len)
{
	length=len;
}
double line::getlen()
{
	return length;
}
int main()
{ line l;
  l.setlen(6.0);
  cout<<l.getlen()<<endl;
  cout<<"_______________________________________________________"<<endl;
  box x("boxx");
  x.setsize(1.0,2.0,3.0);
  cout<<x.getv()<<" ";
  return 0;	
}
