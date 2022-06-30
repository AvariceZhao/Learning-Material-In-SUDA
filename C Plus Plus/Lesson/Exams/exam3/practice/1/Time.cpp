#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
protected:
	int m_hour, m_minute, m_second;						//m_hour值可正可负，详见说明。
public:
	Time(int hour = 0, int minute = 0, int second = 0);				//构造函数
	void set(int hour = 0, int minute = 0, int second = 0);			//设置时间
	Time operator - (const Time & tm);						//计算时间差，可正可负
	friend ostream & operator << (ostream & os, const Time & tm );	//流输出运算符
};
Time::Time(int hour,int minute,int second)
{
    m_hour=hour;
    if(minute>=0&&minute<=59)m_minute=minute;else m_minute=0;
    if(second>=0&&second<=59)m_second=second;else m_second=0;
}
Time Time:: operator - (const Time & tm)			
{
    int hour,minute,second;
    int time1=m_hour*3600+m_minute*60+m_second;
    int time2=tm.m_hour*3600+tm.m_minute*60+tm.m_second;
    if(time1>=time2)
    {
        int t=time1-time2;
        second=t%60;t/=60;
        minute=t%60;t/=60;
        hour=t;
    }
    else
    {
         int t=time2-time1;
        second=t%60;t/=60;
        minute=t%60;t/=60;
        hour=-t;
    }
    return Time(hour,minute,second);
}
void Time::set(int hour,int minute,int second)
{
     m_hour=hour;
    if(minute>=0&&minute<=59)m_minute=minute;else m_minute=0;
    if(second>=0&&second<=59)m_second=second;else m_second=0;
}
ostream & operator<<(ostream &out,const Time &tm)
{
    if(tm.m_hour<0)
    {
        cout<<"-";
        cout<<setw(2)<<setfill('0')<<-1*tm.m_hour<<":"
        <<setw(2)<<setfill('0')<<tm.m_minute<<":"
        <<setw(2)<<setfill('0')<<tm.m_second;
    }
    else
    {
        cout<<setw(2)<<setfill('0')<<tm.m_hour<<":"
        <<setw(2)<<setfill('0')<<tm.m_minute<<":"
        <<setw(2)<<setfill('0')<<tm.m_second;
    }
    return out;
}
class WorldTime:public Time
{
    private:
    int m_timezone;
    public:
    WorldTime(int hour = 0, int minute = 0, int second = 0,int timezone=0):Time(hour,minute,second)
    {
        if(timezone>=-12&&timezone<=12)m_timezone=timezone;
        else m_timezone=0;
    }
    WorldTime(const WorldTime& temp):WorldTime(temp.m_hour,temp.m_minute,0,temp.m_timezone){}
    Time operator-(const WorldTime& temp);
};
Time WorldTime::operator-(const WorldTime& temp)
{

}
int main()
{
	cout << "----------Section 1----------" << endl;
	Time tm1(8,12,153), tm2;
	cout << tm1 << endl;
	cout << tm2 << endl;
	cout << tm2 - tm1 << endl;
	// cout << "----------Section 2----------" << endl;
	// WorldTime wtm1(12, 7, 14, 29), wtm2(-10, 23, 10, 9), wtm3(wtm2);
	// cout << wtm1 << endl;
	// cout << wtm2 << endl;
	// cout << wtm3 << endl;
	// cout << wtm2 - wtm1 << endl;
	// cout << "----------Section 3----------" << endl;
	// wtm1++;
	// cout << wtm1 << endl;
	// wtm2.convert( 20 );
	// wtm3.convert( 8 );
	// cout << wtm2 << endl;
	// cout << wtm3 << endl;
	// cout << "----------Finish-------------" << endl;
    system("pause");
	return 0;
}
