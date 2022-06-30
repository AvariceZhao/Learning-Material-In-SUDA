#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
	int m_x; //点的X坐标
	int m_y;	//点的Y坐标º
public:
	CPoint()
	{
		m_x=0;
		m_y=0;
	}
	CPoint (int x,int y)
	{
		m_x=x;
		m_y=y;
	}
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
	void showPoint()
	{
		cout<<"("<<this->m_x<<","<<this->m_y<<")"<<endl;
	}

};

class CLine
{
	CPoint m_point1;
	CPoint m_point2;
    public:
    void ShowLine();
    double distance();
    CLine(int x1=0,int y1=0,int x2=0,int y2=0)
    {
       m_point1=CPoint(x1,y1);
       m_point2=CPoint(x2,y2);

    }
};
void CLine::ShowLine()
{
    cout<<"Point 1 is:("<<m_point1.getx()<<","<<m_point1.gety()<<")"<<endl;
    cout<<"Point 2 is:("<<m_point2.getx()<<","<<m_point2.gety()<<")"<<endl;
    
  
}
double CLine::distance()
{
     double L=sqrt((m_point1.getx()-m_point2.getx())*(m_point1.getx()-m_point2.getx())+(m_point1.gety()-m_point2.gety())*(m_point1.gety()-m_point2.gety()));
    return L;
}
void main()
{
	CLine line1;
	line1.ShowLine();
	cout<<"Length="<<line1.distance()<<endl;

	CLine line2(1,1,5,5);
	line2.ShowLine();
	cout<<"Length="<<line2.distance()<<endl;
}
