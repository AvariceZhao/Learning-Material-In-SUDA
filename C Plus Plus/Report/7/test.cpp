#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

class CTime
{
	int m_hour,m_mintue,m_second;
public:
	CTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值，否则赋值0时0分0秒
	int SetTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值并返回1，否则不赋值，并返回0
	int getHour();
	int getMinute();
	int getSecond();
	void ShowTime(bool flag);
	//flag为True则以24小时制显示时间，否则以 AM PM的方式显示
	//自己考虑是否需要添加其他成员函数
};
int CTime::SetTime(int hour,int minute,int second)
{
     if(hour>=0&&hour<=23&&minute>=0&&minute<=59&&second>=0&&second<=59)
    {
        m_hour=hour,m_mintue=minute,m_second=second;
        return 1;
    }
    else
    {
        return 0;
    }
}
int CTime::getHour()
{
    return m_hour;
}
int CTime::getMinute()
{
    return m_mintue;
}
int CTime::getSecond()
{
    return m_second;
}
void CTime::ShowTime(bool flag)
{
    if (flag)
    {
        cout<<m_hour<<":"<<setw(2)<<setfill('0')<<m_mintue<<":"<<m_second<<endl;
    }
    else
    {
        if(m_hour>=12)
        {
            cout<<"PM "<<m_hour%12<<":"<<setw(2)<<setfill('0')<<m_mintue<<":"<<m_second<<endl;
        }
        else
        {
             cout<<"AM "<<m_hour%12<<":"<<setw(2)<<setfill('0')<<m_mintue<<":"<<m_second<<endl;
        }
    }

}
CTime::CTime(int hour,int minute,int second)
{
    if(hour>=0&&hour<=23&&minute>=0&&minute<=59&&second>=0&&second<=59)
    {
        m_hour=hour,m_mintue=minute,m_second=second;
    }
    else
    {
        m_hour=0,m_mintue=0,m_second=0;
    }
}
class CDate
{
	int m_year,m_month,m_day;
public:
	CDate(int year=2000,int month=1,int day=1);
	//如果日期合法(不考虑闰年，但考虑月的天数)，则赋值，否则赋值2000年1月1日
	int SetDate(int year=2000,int month=1,int day=1);
	//如果日期合法(不考虑闰年，但考虑月的天数)，则赋值并返回1，否则不赋值，并返回0
	int GetYear();
	int GetMonth();
	int GetDay();
	void ShowDate(bool flag);
	//flag为TRUE，则以中文的方式显示日期，否则以MM/DD/YYYY的方式显示日期
	//自己考虑是否需要添加其他成员函数
};
void CDate::ShowDate(bool flag)
{
    if(flag)
    {
        cout<<m_year<<"年"<<m_month<<"月"<<m_day<<"号"<<endl;
    }
    else
    {
        cout<<m_month<<"/"<<m_day<<"/"<<m_year<<endl;
    }
}
CDate::CDate(int year,int month,int day)
{
    int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(day>=1&&day<=d[month])
    {
        m_year=year;
        m_month=month;
        m_day=day;
    }else
    {
        m_year=2002;
        m_month=1;
        m_day=1;
    }
}
int CDate::SetDate(int year,int month,int day)
{
    int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(day>=1&&day<=d[month])
    {
        m_year=year;
        m_month=month;
        m_day=day;
        return 1;
    }else
    {
        return 0;
    }
}
int CDate::GetYear()
{
    return m_year;
}
int CDate::GetMonth()
{
    return m_month;
}
int CDate::GetDay()
{
    return m_day;
}
class CDateTime:public CDate,public CTime
{
	CTime m_time;
	CDate m_date;
public:
	//添加必要的构造函数
	//int SetDateTime(...); 自己设计参数，考虑该函数的返回值加以表示全部正确、日期不对、时间不对等情况
	//void ShowDateTime(...); 自己设计参数，考虑可以中文日期和西文日期格式，以及24小时和AM PM都可以控制
	//添加自己认为必要的其他成员函数
    CDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0)
    {
        m_time=CTime(hour,minute,second);
        m_date=CDate(year,month,day);
    }
    void ShowDateTime(bool flag1,bool flag2);
    int SetDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
    int GetMonth();
    int GetMinute();
};
// int CDateTime::GetMonth()
// {
//     return m_date.GetMonth();
// }
// int CDateTime::GetMintue()
// {
//     return m_time.getMinute();
// }
void CDateTime::ShowDateTime(bool flag1,bool flag2)
{
    m_date.ShowDate(flag1);
    m_time.SetTime(flag2);
}
int CDateTime::SetDateTime(int year,int month,int day,int hour,int minute,int second)
{
    bool DateStatus=m_date.SetDate(year,month,day);
    bool TimeStatus=m_time.SetTime(hour,minute,second);
    if(DateStatus&&TimeStatus)return 1;
    else if (!DateStatus)return -1;
    else if (!TimeStatus)return -2;
}
int main()
{

	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true);	//第1个参数表示以英文方式显示日期, 第2个参数表示以24小时制方式显示时间

	CDateTime d2;
	d2.ShowDateTime(true, false);		//第1个参数表示以中文方式显示日期, 第2个参数表示以AM PM的方式显示时间

	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"日期和时间数据设置正确!"<<endl;
		break;
	case -1:
		cout<<"日期数据设置不正确!"<<endl;
		break;
	case -2:
		cout<<"时间数据设置不正确!"<<endl;
		break;
	}
	d2.ShowDateTime(false, false);		//第1个参数表示以英文方式显示日期, 第2个参数表示以AM PM的方式显示时间

//	cout<<"月="<<d2.GetMonth()<<endl;		//认真考虑一下如何实现此操作？
//	cout<<"分钟="<<d2.GetMinute()<<endl;		//认真考虑一下如何实现此操作？
}
