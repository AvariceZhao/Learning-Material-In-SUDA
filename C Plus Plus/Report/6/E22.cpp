#include<iostream>
#include<iomanip>
using namespace std;
 const double PI=3.14159;
class CCircle
{
    private:
    double m_x,m_y,m_r;
   
    public:
    void set_xy(double x,double y)
    {
        m_x=x;
        m_y=y;
    }
    void set_r(double r)
    {
        m_r=r;
    }
    double get_circlum()
    {
        return 2*PI*m_r;
    }
    double get_area()
    {
        return PI*m_r*m_r;
    }

};
int main()
{
	CCircle c1;
	double x,y,r1,r2;
    cout<<"输入圆心坐标和半径"<<endl;
	cin>>x>>y>>r1;
	c1.set_xy(x,y);
	c1.set_r(r1);
	cout<<"圆周长和面积: "<<fixed<<setprecision(3)<<c1.get_circlum()<<" "<<c1.get_area()<<endl;
	cout<<"输入新的半径:"<<endl;
	cin>>r2;
	c1.set_r(r2);
	cout<<"圆周长和面积: "<<fixed<<setprecision(3)<<c1.get_circlum()<<" "<<c1.get_area()<<endl;

	system("pause");
	return 0;
}
