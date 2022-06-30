#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class CGoods
{
private:
int m_num; //��Ʒ���
string m_name; //��Ʒ����
float m_price; //��Ʒ�۸�
public:
CGoods (int, const string&, float);
friend ostream& operator<<(ostream&, const CGoods&);
//��Ʒ���ơ���Ʒ��ź���Ʒ�۸����ʾ��ʽ��Ҫ��Ϊռ10�С��Ҷ���
};
CGoods::CGoods(int num,const string & name,float price):m_num(num),m_name(name),m_price(price){};

ostream& operator<<(ostream &out,const CGoods & temp)
{
    out<<setw(10)<<right<<temp.m_num
    <<setw(10)<<right<<temp.m_name
    <<setw(10)<<right<<temp.m_price;
    return out;
}
class CRouter:public CGoods
{
    private:
    double m_Frequency;
    int m_channels;
    public:
    CRouter(int num=1,string name="MB",float price=100.0,double frequency=2.4,int channels=8):CGoods(num,name,price)
    {
        m_Frequency=frequency;
        m_channels=channels;
    }
    int GetChannels()const
    {
        return m_channels;
    }
    double GetFrequency()const
    {
        return m_Frequency;
    }
    CRouter& operator++()
    {
        m_channels++;
        return *this;
    }
    
    CRouter operator++(int)
    {
        auto t=*this;
        m_channels++;
        return t;
    } 
    friend ostream & operator<<(ostream &out,const CRouter &temp)
    {
        out<<(CGoods)temp
        <<setw(10)<<right<<temp.GetFrequency()
        <<setw(10)<<right<<temp.GetChannels();
        return out;
    }

};
void ReadData(vector<CRouter> &s,const char path[])
{
    ifstream iFile(path);
    int num,channels;string name;float price;double frequency;
    while(iFile>>num>>name>>price>>frequency>>channels)
    {
        s.push_back({num,name,price,frequency,channels});
    }
}

void DisplayData(vector<CRouter> &s)
{
    for(auto item:s)
    cout<<item<<endl;
}
CRouter FindMax(const vector<CRouter> &s)
{
    CRouter ans;
    double maxs=0;
    for(auto item:s)
    {
        if(item.GetChannels()*item.GetFrequency()>maxs)
        {
            maxs=item.GetChannels()*item.GetFrequency();
            ans=item;
        }
    }
    return ans;


}
int main()
{
vector<CRouter> s;
ReadData(s,"D:\\Data.txt");
cout<<"��ȡ��ɺ������Ϊ"<<endl;
DisplayData(s);
CRouter t;
cout<<endl<<"·��������ĳ�ʼֵΪ"<<endl<<t<<endl;
t=FindMax(s);
cout<<endl<<"�˻���������Ԫ��Ϊ"<<endl<<t<<endl;
cout<<endl<<"�˻���������Ԫ�ؽ��������������ֱ�����:"<<endl;
cout<<t++<<endl;
cout<<t<<endl;
cout<<++t<<endl;
cout<<t<<endl;
system("pause");
return 0;
}
