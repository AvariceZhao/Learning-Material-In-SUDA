#include<iostream>
#include<iomanip>
using namespace std;
const double PI=3.14159;
class CColumn
{
	private:
    double m_x,m_y,m_r,m_h;
    
    public:
    void SetXY(double x,double y)
    {
        m_x=x;
        m_y=y;
    }
    void SetR(double r)
    {
        m_r=r;
    }
    void SetH(double h)
    {
        m_h=h;
    }
    double GetBottomCirclum()
    {
        return 2*PI*m_r;
    }
    double GetBottomArea()
    {
        return PI*m_r*m_r;
    }
    double GetSideArea()
    {
        return GetBottomCirclum()*m_h;
    }
    double GetVolume()
    {
        return GetBottomArea()*m_h;
    }
};
int main()
{
	CColumn c1;
	double x,y,r1,r2,h1,h2;
	cout<<"����Բ�����ꡢ�뾶�͸�"<<endl;
	cin>>x>>y>>r1>>h1;
	c1.SetXY(x,y);
	c1.SetR(r1);
	c1.SetH(h1);
	cout<<"Բ���ĵ����ܳ����������������������"<<endl;
	cout<<fixed<<setprecision(3)<<c1.GetBottomCirclum()<<" "
		<<c1.GetBottomArea()<<" "
		<<c1.GetSideArea()<<" "
		<<c1.GetVolume()<<endl;
    cout<<"�����Բ�뾶�͸�:"<<endl;
	cin>>r2>>h2;
	c1.SetR(r2);
	c1.SetH(h2);
	cout<<"Բ���ĵ����ܳ����������������������"<<endl;
	cout<<fixed<<setprecision(3)<<c1.GetBottomCirclum()<<" "
		<<c1.GetBottomArea()<<" "
		<<c1.GetSideArea()<<" "
		<<c1.GetVolume()<<endl;

	system("pause");
	return 0;
}
