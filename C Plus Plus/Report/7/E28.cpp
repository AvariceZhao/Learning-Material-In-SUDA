#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
class CTime
{
	int m_hour,m_mintue,m_second;
public:
	CTime(int hour=0,int minute=0,int second=0);
	//���ʱ��Ϸ�����ֵ������ֵ0ʱ0��0��
	int SetTime(int hour=0,int minute=0,int second=0);
	//���ʱ��Ϸ�����ֵ������1�����򲻸�ֵ��������0
	int getHour();
	int getMinute();
	int getSecond();
	void ShowTime(bool flag);
	//flagΪTrue����24Сʱ����ʾʱ�䣬������ AM PM�ķ�ʽ��ʾ
	//�Լ������Ƿ���Ҫ���������Ա����
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
        cout<<setw(2)<<setfill('0')<<m_hour<<":"<<setw(2)<<setfill('0')<<m_mintue<<":"<<setw(2)<<setfill('0')<<m_second<<endl;
    }
    else
    {
        if(m_hour>=12)
        {
            cout<<"PM "<<setw(2)<<setfill('0')<<m_hour%12<<":"<<setw(2)<<setfill('0')<<m_mintue<<":"<<setw(2)<<setfill('0')<<m_second<<endl;
        }
        else
        {
             cout<<"AM "<<setw(2)<<setfill('0')<<m_hour%12<<":"<<setw(2)<<setfill('0')<<m_mintue<<":"<<setw(2)<<setfill('0')<<m_second<<endl;
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
	//������ںϷ�(���������꣬�������µ�����)����ֵ������ֵ2000��1��1��
	int SetDate(int year=2000,int month=1,int day=1);
	//������ںϷ�(���������꣬�������µ�����)����ֵ������1�����򲻸�ֵ��������0
	int GetYear();
	int GetMonth();
	int GetDay();
	void ShowDate(bool flag);
	//flagΪTRUE���������ĵķ�ʽ��ʾ���ڣ�������MM/DD/YYYY�ķ�ʽ��ʾ����
	//�Լ������Ƿ���Ҫ���������Ա����
};
void CDate::ShowDate(bool flag)
{
    if(flag)
    {
        cout<<m_year<<"��"<<setw(2)<<setfill('0')<<m_month<<"��"<<setw(2)<<setfill('0')<<m_day<<"��"<<endl;
    }
    else
    {
        cout<<setw(2)<<setfill('0')<<m_month<<"/"<<setw(2)<<setfill('0')<<m_day<<"/"<<m_year<<endl;
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
class CDateTime
{
	CTime m_time;
	CDate m_date;
public:
	//��ӱ�Ҫ�Ĺ��캯��
	//int SetDateTime(...); �Լ���Ʋ��������Ǹú����ķ���ֵ���Ա�ʾȫ����ȷ�����ڲ��ԡ�ʱ�䲻�Ե����
	//void ShowDateTime(...); �Լ���Ʋ��������ǿ����������ں��������ڸ�ʽ���Լ�24Сʱ��AM PM�����Կ���
	//����Լ���Ϊ��Ҫ��������Ա����
    CDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0)
    {
        m_time=CTime(hour,minute,second);
        m_date=CDate(year,month,day);
    }
    void ShowDateTime(bool flag1,bool flag2);
    int SetDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0);
    int GetMinute();
    int GetMonth();
};
int CDateTime::GetMinute()
{
   return m_time.getMinute();
}
int CDateTime::GetMonth()
{
    return m_date.GetMonth();
}
void CDateTime::ShowDateTime(bool flag1,bool flag2)
{
    m_date.ShowDate(flag1);
    m_time.ShowTime(flag2);
}
int CDateTime::SetDateTime(int year,int month,int day,int hour,int minute,int second)
{
    bool DateStatus=m_date.SetDate(year,month,day);
    bool TimeStatus=m_time.SetTime(hour,minute,second);
    if(DateStatus&&TimeStatus)return 1;
    else if (!DateStatus)return -1;
    else if (!TimeStatus)return -2;
    else
    return 0;
}
int main()
{

	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true);	//��1��������ʾ��Ӣ�ķ�ʽ��ʾ����, ��2��������ʾ��24Сʱ�Ʒ�ʽ��ʾʱ��

	CDateTime d2;
	d2.ShowDateTime(true, false);		//��1��������ʾ�����ķ�ʽ��ʾ����, ��2��������ʾ��AM PM�ķ�ʽ��ʾʱ��

	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"���ں�ʱ������������ȷ!"<<endl;
		break;
	case -1:
		cout<<"�����������ò���ȷ!"<<endl;
		break;
	case -2:
		cout<<"ʱ���������ò���ȷ!"<<endl;
		break;
	}
	d2.ShowDateTime(false, false);		//��1��������ʾ��Ӣ�ķ�ʽ��ʾ����, ��2��������ʾ��AM PM�ķ�ʽ��ʾʱ��

	cout<<"��="<<d2.GetMonth()<<endl;		//���濼��һ�����ʵ�ִ˲�����
	cout<<"����="<<d2.GetMinute()<<endl;		//���濼��һ�����ʵ�ִ˲�����
    system("pause");
}
