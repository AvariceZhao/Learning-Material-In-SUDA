#include<iostream>
using namespace std;
// 为了便于测试，提供一个系统日期类，并定义全局对象表示当前系统日期
class CSystemTime
{
private:
    int m_year, m_month, m_day;
public:
    void setDate(int y,int m, int d)
    {
        m_year=y;
        m_month=m;
        m_day=d;
    }
    int getYear()const{return m_year;}
    int getMonth()const{return m_month;}
    int getDay()const{return m_day;}
      int operator-(CSystemTime t){
        return m_year * 360 + m_month * 30 + m_day - (t.m_year * 360 + t.m_month * 30 + t.m_day) + 1;
    }
};
CSystemTime  systemTime;   // 全局变量表示当前系统时间
class CAount{
    private:
    double m_Money;
    static double m_InterestRate;
    CSystemTime m_time;

    public:
    CAount()
    {
        m_Money=0;
    }
 
    static void SetInterestRate(double temp)
    {
        m_InterestRate=temp;
    }
    double GetInterestRate()
    {
        return m_InterestRate;
    }
    void SaveMoney(double money)
    {
        m_Money+=money;
        m_time=systemTime;
    }
    double CalcInterset(double money)
    {
    if(money > m_Money) return 0;
    int day = systemTime - m_time;
    return money * m_InterestRate / 360 * day;
    }
    int LendMoney(double money)
    {
        if(money>m_Money)
        return -1;
        else
        {
            m_Money-=money;
             money += CalcInterset(money);
            return money;
        }
    }
    friend ostream &operator<<(ostream &out,CAount temp)
    {
        cout<<temp.m_time.getYear()<<"-"<<temp.m_time.getMonth()<<"-"<<temp.m_time.getDay()<<" "<<temp.m_Money<<" "<<temp.GetInterestRate()<<endl;
        return out;
    }
    void SaveInterest()
    {
         m_Money += CalcInterset(m_Money);
         m_time = systemTime;
    }
};
double CAount::m_InterestRate = 0.036;
int main()
{
    CAount aount;
    int year,month, day;
    double money,istate;
    cout<<"输入当前日期(年月日):"<<endl;
    cin>>year>>month>>day;
    systemTime.setDate(year,month,day);
    cout<<"输入存款金额:"<<endl;
    cin>>money;
    aount.SaveMoney(money);
    cout<<"当前账户信息:"<<endl;
    cout<<aount<<endl;

    cout<<"输入新的日期(年月日):"<<endl;
    cin>>year>>month>>day;
    systemTime.setDate(year,month,day);
    aount.SaveInterest();
    cout<<"当前账户信息:"<<endl;
    cout<<aount<<endl;

    cout<<"输入新的日期(年月日):"<<endl;
    cin>>year>>month>>day;
    systemTime.setDate(year,month,day);
    CAount::SetInterestRate(0.2);
    cout<<"输入取款金额:"<<endl;
    cin>>money;
    istate=aount.LendMoney(money);
    if (istate<0)
        cout<<"账户本金不足"<<endl;
    else
        cout<<"取款: "<<istate<<endl;

    cout<<"当前账户信息:"<<endl;
    cout<<aount<<endl;
	//system("pause");
	return 0;
}
