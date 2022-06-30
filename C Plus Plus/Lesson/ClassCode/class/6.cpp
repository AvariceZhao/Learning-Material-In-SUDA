//fw
#include<bits/stdc++.h>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define endl '\n'
using namespace std;
typedef long long ll;
const double pi=3.1415269;
class CCircle
{

	int m_x,m_y;double m_r;
	public:
	CCircle(int x,int y,double r)
	{
		m_x=x,m_y=y,m_r=max(0.0,r);
	}
	~CCircle()
	{
		cout<<"CCircle"<<endl;
	}
	int getx()const
	{
		return m_x;
	}
	int gety()const
	{
		return m_y;
	}
	double getr()const
	{
		return m_r;
	}
	double getgirth()const
	{
		return 2*pi*m_r;
	}
	double gets()const
	{
		return pi*m_r*m_r;
	}
};

class CCylinder:private CCircle
{
	double m_h;
public:
	CCylinder(int x,int y,double r,double h):CCircle(x,y,r)
	{
//		cout<<"CCylinder"<<endl;
		m_h=max(0.0,h);
	}
	~CCylinder()
	{
		cout<<"CCylinder"<<endl;
	}
};
int main()
{
	//ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	CCylinder a(1,1,1.0,2.0);
	cout<<a.getx()<<endl<<a.gety()<<endl<<a.getr()<<endl<<a.getgirth()<<endl<<a.gets()<<endl;
	return 0;
}
