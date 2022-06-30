#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std;
class Motor
{
private:
int m_Type; //������� 0-ֱ�� 1-����
int m_Power; //������ʣ�����Ϊ������
public:
Motor(int Type, int Power);
int GetPower()const; //��ȡ�������
int SetPower(int Power); //�޸ĵ�����ʣ�����ֵ��ʾ�޸��Ƿ�ɹ���0-ʧ�� 1-�ɹ�
friend ostream& operator<<(ostream &Out, const Motor &Obj);
};

Motor::Motor(int Type, int Power):m_Type(Type),m_Power(Power){};
int Motor::GetPower()const{return m_Power;}
int Motor::SetPower(int Power)
{
    if(Power>0)
    {
        m_Power=Power;
        return 1;
    }
    else
        return 0;
}
ostream& operator<<(ostream &Out, const Motor &Obj)
{
    if(Obj.m_Type)
    Out<<setw(4)<<"AC";
    else
    Out<<setw(4)<<"DC";
    Out<<setw(6)<<Obj.GetPower();
    return Out;
}
class Appliance
{
private:
string m_Name;
double m_Weight; //����������Ϊ������
public:
Appliance(const string &Name, double Weight);
double GetWeight()const; //��ȡ����
int SetWeight(double Weight); //�޸�����������ֵ��ʾ�޸��Ƿ�ɹ���0-ʧ�� 1-�ɹ�
friend ostream& operator<<(ostream &Out, const Appliance &Obj);
};
Appliance ::Appliance(const string &Name, double Weight):m_Name(Name),m_Weight(Weight){};
double Appliance::GetWeight()const{return m_Weight;}
int Appliance::SetWeight(double Weight)
{
    if(Weight>0){m_Weight=Weight;return 1;}
    else return 0;
}
ostream& operator<<(ostream &Out, const Appliance &Obj)
{
    Out<<setw(6)<<Obj.m_Name<<setw(6)<<fixed<<setprecision(1)<<Obj.m_Weight;
    return Out;

}
class WashMachine:public Appliance
{
    private:
    Motor m_Motor;
    int m_Volume;
    public:
    WashMachine(string name="M9",int type=0,int power=20,double weight=20.0,int volume=20):Appliance(name,weight),m_Motor(type,power),m_Volume(volume){};
    int GetVolume()const{return m_Volume;}
    WashMachine & operator++()
    {
        m_Motor.SetPower(m_Motor.GetPower()+10);
        this->SetWeight(this->GetWeight()+10);
        m_Volume+=10;
    }
     WashMachine  operator++(int)
    {   auto t=*this;
        m_Motor.SetPower(m_Motor.GetPower()+10);
        this->SetWeight(this->GetWeight()+10);
        m_Volume+=10;
        return t;
    }
    friend ostream & operator<<(ostream &out,const WashMachine &temp)
    {
        out<<(Appliance)temp;
        out<<temp.m_Motor;
        out<<setw(5)<<temp.GetVolume();
        return out;
    }

};
int ReadFileData(const char path[],vector<WashMachine> &data)
{
    ifstream iFile(path);
    if(iFile.fail())return 0;
    string name;int type,power,volume;double weight;
    while(iFile>>name>>weight>>type>>power>>volume)
    {
        data.push_back({name,weight,type,power,volume});

    }
    iFile.close();
}
void DisplayData(const vector<WashMachine> &data)
{
    for(auto item:data)
    {
        cout<<item<<endl;
    }
}
vector<WashMachine> FindData(const vector<WashMachine> &data,int vol)
{
    vector<WashMachine> ans;
    for(auto item:data)
    {
        if(item.GetVolume()>vol)
        ans.push_back(item);

    }
    return ans;
}
vector<WashMachine> FindData(const vector<WashMachine> &data,double weight)
{
    vector<WashMachine> ans;
    for(auto item:data)
    {
        if(item.GetWeight()>weight)
        ans.push_back(item);

    }
    return ans;
}
int main()
{
vector<WashMachine> data,res;
if (ReadFileData("d:\\info.txt", data)==0)
return 0;
cout<<"�ļ���ȡ��ɺ��ϴ�»���Ϣ����:"<<endl;
DisplayData(data);
res = FindData(data, 30);
cout<<endl<<"ϴ���ݻ�����30��ϴ�»���Ϣ������ʾ:"<<endl;
DisplayData(res);
res = FindData(data, 20.0);
cout<<endl<<"��������20.0��ϴ�»���Ϣ������ʾ:"<<endl;
DisplayData(res);
WashMachine d;
cout<<endl<<"������ϴ�»�����������������������ʾ:"<<endl;
cout<<d<<endl;
cout<<d++<<endl;
cout<<d<<endl;
cout<<++d<<endl;
cout<<d<<endl;
system("pause");
}
