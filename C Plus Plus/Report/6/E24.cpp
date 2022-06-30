//E24Ô´´úÂë
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
  const double PI=3.14159;
class CCircle
{
     private:
    double m_x,m_y,m_r;

    public:
    CCircle(double x=0,double y=0,double r=0)
    {
        m_x=x;m_y=y;m_r=r;
    }
    void set_xy(double x,double y)
    {
        m_x=x;
        m_y=y;
    }
    void set_r(double r)
    {
        m_r=r;
    }
    friend ostream &operator <<(ostream &out,  CCircle temp)
    {
        cout<<fixed<<setprecision(3)<<"("<<temp.m_x<<","<<temp.m_y<<")"<<temp.m_r<<" "<<2*PI*temp.m_r<<" "<<PI*temp.m_r*temp.m_r<<endl;
        return out;
    }



	CCircle operator+(const CCircle temp)
    {
        return CCircle(m_x,m_y,m_r+temp.m_r);
    }
    CCircle operator-(const CCircle temp)
    {
        return CCircle(m_x,m_y,abs(m_r-temp.m_r));
    }
    CCircle &operator++()
    {
        m_r+=1.0;
        return *this;
    }
    CCircle operator++(int i)
    {
        CCircle temp=*this;
        m_r+=1.0;
        return temp;
    }
    CCircle &operator--()
    {
        m_r-=1.0;
        return *this;
    }
    CCircle operator--(int i)
    {
        CCircle temp=*this;
        m_r-=1.0;
        return temp;
    }
    bool operator<(const CCircle temp)const
    {
        return m_r<temp.m_r;
    }
    bool operator>(const CCircle temp)const
    {
        return m_r>temp.m_r;
    }
    bool operator==(const CCircle temp)const
    {
        return m_x==temp.m_x&&m_y==temp.m_y&&m_r==temp.m_r;
    }
    bool operator!=(const CCircle temp)const
    {
        return m_x!=temp.m_x||m_y!=temp.m_y||m_r!=temp.m_r;
    }
    bool operator&(const CCircle temp)const
    {
        return m_x==temp.m_x&&m_y==temp.m_y;
    }
    int operator|(const CCircle temp)const
    {
        double d=sqrt((m_x-temp.m_x)*(m_x-temp.m_x)+(m_y+temp.m_y)*+(m_y+temp.m_y));
        if(d==m_r+temp.m_r||d==abs(m_r-temp.m_r))return 2;
        else if (d>temp.m_r+m_r)return 3;
        else if(m_r+temp.m_r>d)return 1;
        else return 0;

    }
   
};
int main()
{
	CCircle c1,c2,c3,c4;
	double x1,y1,x2,y2,r1,r2;
	int istate;
	cout<<"请输入圆心坐标和半径: "<<endl;
	cin>>x1>>y1>>r1;
	c1.set_xy(x1,y1);
	c1.set_r(r1);
	cout<<c1<<endl;
	cout<<"请输入圆心坐标和半径: "<<endl;
	cin>>x2>>y2>>r2;
	c2.set_xy(x2,y2);
	c2.set_r(r2);
	cout<<c2<<endl;

    c3=c1+c2;
    cout<<" 两圆相加: "<<c3<<endl;
    c4=c3-c2;
    cout<<" 两圆相减: "<<c4<<endl;
    ++c4;
    cout<<" C4前自增: "<<c4<<endl;
    cout<<" C4后自增: "<<c4++<<" C4自增后: "<<c4<<endl;
    --c4;
    cout<<" C4前自减: "<<c4<<endl;
    cout<<" C4后自减: "<<c4--<<" C4自减后: "<<c4<<endl;

    cout<<"c1: "<<c1<<" c2: "<<c2<<endl;
    if (c1>c2)
        cout<<"c1>c2"<<endl;
    else if (c1<c2)
        cout<<"c1<c2"<<endl;
    else
        cout<<"c1<>c2"<<endl;   // 表示无比较结果

    cout<<"c1: "<<c1<<" c4: "<<c4<<endl;
    if (c1==c4)
        cout<<"c1==c4"<<endl;
    else if (c1 != c4)
        cout<<"c1!=c4"<<endl;
    else
        cout<<"c1<>c4"<<endl;   // 表示无比较结果


    if (c1&c4)
        cout<<"c1与c4同心"<<endl;

    istate = c1|c2;
    switch(istate)
    {
    case 0:
        cout<<"c1包含c2"<<endl;
        break;
    case 1:
        cout<<"c1与c2相交"<<endl;
        break;
    case 2:
        cout<<"c1与c2相切"<<endl;
        break;
    case 3:
        cout<<"c1与c2相离"<<endl;
        break;
    default:
        cout<<"c1与c2位置判断错误"<<endl;
    }
    istate = c3|c1;
    switch(istate)
    {
    case 0:
        cout<<"c3包含c1"<<endl;
        break;
    case 1:
        cout<<"c3与c1相交"<<endl;
        break;
    case 2:
        cout<<"c3与c1相切"<<endl;
        break;
    case 3:
        cout<<"c3与c1相离"<<endl;
    default:
        cout<<"c3与c1位置判断错误"<<endl;
    }

	//system("pause");
	return 0;
}
