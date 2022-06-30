#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class Time
{
protected:
int m_hour, m_minute, m_second; //m_hour 值可正可负，详见说明。
public:
Time(int hour = 0, int minute = 0, int second = 0); //构造函数
void set(int hour = 0, int minute = 0, int second = 0); //设置时间
Time operator - (const Time & tm); //计算时间差，可正可负
friend ostream & operator << (ostream & os, const Time & tm );//流输出运算符
};
Time::Time(int hour,int minute,int second)
{
    m_hour=hour;
    if(minute>=0&&minute<=59)m_minute=minute;
    else m_minute=0;
    if(second>=0&&second<=59)m_second=second;
    else m_second=0;

}
Time Time::operator- (const Time & tm)
{
    int hour,minute,second;
    int t1=m_hour*3600+m_minute*60+m_second;
    int t2=tm.m_hour*3600+tm.m_minute*60+tm.m_second;
    int time=t1-t2;
    if(time>=0)
    {
        second=time%60;time/=60;
        minute=time%60;time/=60;
        hour=time;
    }
    else
    {   time=-time;
        second=time%60;time/=60;
        minute=time%60;time/=60;
        hour=-1*time;
    }
    return Time(hour,minute,second);
}
ostream &operator<<(ostream & out,const Time &temp)
{
    if(temp.m_hour<0)
    {
        out<<"-";
    }
    out<<setw(2)<<setfill('0')<<abs(temp.m_hour)<<":";
    out<<setw(2)<<setfill('0')<<temp.m_minute<<":";
    out<<setw(2)<<setfill('0')<<temp.m_second;
    return out;
}
class WorldTime:public Time
{
    private:
    int m_timezone;
    public:

    WorldTime(int timezone,int hour,int minute,int second):Time(hour,minute,second),m_timezone(timezone){};

    WorldTime(const WorldTime &  temp):WorldTime(temp.m_timezone,temp.m_hour,temp.m_minute,0){};

    Time operator-(const WorldTime &temp)
    {   int hour,minute,second;
        int time1=(m_hour-m_timezone)*3600+m_minute*60+m_second;
        int time2=(temp.m_hour-temp.m_timezone)*3600+temp.m_minute*60+temp.m_second;
        
        int time=time1-time2;
         if(time>=0)
    {
        second=time%60;time/=60;
        minute=time%60;time/=60;
        hour=time;
    }
    else
    {
        second=time%60;time/=60;
        minute=time%60;time/=60;
        hour=-1*time;
    }
    return Time(hour,minute,second);
    }
    WorldTime operator++(int)
    {
        auto t=(*this);
        m_timezone+=1;
        if(m_timezone>12)m_timezone=-12;
        return t;
    }
    void convert(int timezone)
    {
        if(timezone>12||timezone<-12)timezone=0;
        int hour=timezone-m_timezone;
        m_hour+=hour;m_timezone=timezone;
        if(m_hour>24)m_hour-=24;
        if(m_hour<0)m_hour+=24;
    }
    friend ostream & operator<<(ostream &out,const WorldTime &temp)
    {
        if(temp.m_timezone>=0)
        out<<'['<<'+'<<setw(2)<<setfill('0')<<temp.m_timezone<<"] ";
        else
       out<<'['<<'-'<<setw(2)<<setfill('0')<<-temp.m_timezone<<"] ";
        out<<(Time)temp;
        return out;
    }
};
int main()
{
cout << "----------Section 1----------" << endl;
Time tm1(8,12,153), tm2;
cout << tm1 << endl;
cout << tm2 << endl;
cout << tm2 - tm1 << endl;
cout << "----------Section 2----------" << endl;
WorldTime wtm1(12, 7, 14, 29), wtm2(-10, 23, 10, 9), wtm3(wtm2);
cout << wtm1 << endl;
cout << wtm2 << endl;
cout << wtm3 << endl;
cout << wtm2 - wtm1 << endl;
cout << "----------Section 3----------" << endl;
wtm1++;
cout << wtm1 << endl;
wtm2.convert( 20 );
wtm3.convert( 8 );
cout << wtm2 << endl;
cout << wtm3 << endl;
cout << "----------Finish-------------" << endl;
system("pause");
return 0;
}
