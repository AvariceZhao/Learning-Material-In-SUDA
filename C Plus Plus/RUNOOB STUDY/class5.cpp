#include<bits/stdc++.h>
using namespace std;
class line{//类的构造函数 
	public:
		void setl(float l1);
		float getl();
		line(float l);
	private:
		float l; 
};
float line::getl()
{
	return l;
}
void line::setl(float l1)
{
	l=l1;
}
//line::line(float l1):setl(l1)
line::line(float l1)
{	l=l1;
	cout<<"Object is being created, length = "<<l1<<endl;
}
int main()
{	line L(2.0);
	L.setl(5.0);
	cout<<L.getl()<<endl;
	return 0;
}
