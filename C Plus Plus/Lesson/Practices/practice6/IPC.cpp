#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
class CPU
{
private:
double m_MainFreq; //主频，单位 GHz
int m_CoreNum; //核心数
double m_Power; //功率，单位：W
public:
CPU(double MainFreq, int CoreNum, double Power);
double GetMainFreq(void)const; //获取主频
CPU& operator++(); //前自增，主频加 0.1，核心数加 2，功率加 1.0
CPU operator++(int); //后自增，规则同上
friend ostream& operator<<(ostream& Out, const CPU& Obj); //输出 CPU 的参数，
//主频占 6 列，小数部分保留 2 位，左对齐
//核心数占 3 列，左对齐
//功率占 6 列，小数部分保留 1 位，左对齐
};
CPU::CPU(double MainFreq, int CoreNum, double Power):m_CoreNum(CoreNum),m_MainFreq(MainFreq),m_Power(Power){};
double CPU::GetMainFreq()const{return m_MainFreq;}
CPU& CPU::operator++()
{
    m_MainFreq+=0.1;
    m_CoreNum+=2;
    m_Power+=1.0;
    return (*this);
}
CPU CPU::operator++(int)
{
    auto t=(*this);
    m_MainFreq+=0.1;
    m_CoreNum+=2;
    m_Power+=1.0;
    return t;
}
ostream & operator<<(ostream &out,const CPU& temp)
{
    out<<left<<fixed<<setprecision(2)<<setw(6)<<temp.m_MainFreq;
    out<<left<<setw(3)<<temp.m_CoreNum;
    out<<left<<setw(6)<<fixed<<setprecision(1)<<temp.m_Power;
    return out;
}

class Computer
{
private:
CPU m_CPU;
int m_Memory; //内存容量，单位：G
int m_HD; //硬盘容量，单位：G
public:
Computer(double CPU_MainFreq, int CPU_CoreNum, double CPU_Power, int Memory, int HD);
CPU GetCPU(void)const; //获取 CPU 数据
double GetMemory(void)const; //获取内存容量
Computer& operator++(); //前自增，CPU 部分自增规则同 CPU 类，内存扩大 4G，硬盘扩大 128G
Computer operator++(int); //后自增，规则同上
friend ostream& operator<<(ostream& Out, const Computer& Obj);
//CPU 部分数据的输出规则与 CPU 类中定义相同
//内存容量占 6 列，左对齐
//硬盘容量占 8 列，左对齐
};
Computer::Computer(double CPU_MainFreq, int CPU_CoreNum, double CPU_Power, int Memory, int HD):m_CPU(CPU_MainFreq,CPU_CoreNum,CPU_Power),m_Memory(Memory),m_HD(HD){};
CPU Computer::GetCPU()const{return m_CPU;}
double Computer::GetMemory()const{return m_Memory;}
Computer& Computer::operator++()
{
    ++m_CPU;
    m_Memory+=4;
    m_HD+=128;
    return (*this); 
}
Computer Computer::operator++(int)
{
    auto t=(*this);
    m_CPU++;
    m_Memory+=4;
    m_HD+=128;
    return t; 
}
ostream &operator<<(ostream &out,const Computer &temp)
{
    out<<temp.m_CPU;
    out<<left<<setw(6)<<temp.m_Memory;
    out<<left<<setw(8)<<temp.m_HD;
    return out;
}



class IPC:public Computer
{
private:
int m_ProtectGrade; //防护等级
static int m_Counts; //工控机数量
public:
IPC(double CPU_MainFreq=3.7, int CPU_CoreNum=6, double CPU_Power=95.0, int Memory=16, 
int HD=512, int ProtectGrade=65);
IPC(const IPC& Obj);
double GetProtectGrade(void)const; //获取防护等级
static int GetCounts(void); //获取当前工控机数量
IPC& operator++(); //前自增，Computer 数据自增规则同上，防护等级加 1
IPC operator++(int); //后自增，规则同上
friend ostream& operator<<(ostream& Out, const IPC& Obj);
//Computer 部分数据的输出规则与 Computer 类中定义相同
//防护等级占 5 列，左对齐
~IPC();
};
int IPC::m_Counts=0;
IPC::IPC(double CPU_MainFreq, int CPU_CoreNum, double CPU_Power, int Memory, int HD, int ProtectGrade):Computer(CPU_MainFreq,CPU_CoreNum,CPU_Power,Memory,HD),m_ProtectGrade(ProtectGrade)
{
    m_Counts+=1;
};
IPC::IPC(const IPC& Obj):Computer(Obj),m_ProtectGrade(Obj.GetProtectGrade())
{
    m_Counts+=1;
}
double IPC::GetProtectGrade()const{return m_ProtectGrade;}
int IPC::GetCounts(){return m_Counts;}
IPC & IPC::operator++()
{
    Computer::operator++();
  
    m_ProtectGrade+=1;
    return (*this);
}
IPC IPC::operator++(int)
{   
    auto t=(*this);
    Computer::operator++();
    m_ProtectGrade+=1;
    return t;
}
ostream & operator<<(ostream &out,const IPC &temp)
{
    out<<(Computer)temp;
    out<<left<<setw(5)<<temp.m_ProtectGrade;
    return out;
}
IPC::~IPC()
{
    m_Counts--;
}
void ReadIPCFile(const char path[],vector<IPC> &A)
{
    ifstream iFile(path);
    double CPU_MainFreq; int CPU_CoreNum;double CPU_Power;int Memory;int HD;int ProtectGrade;
    while(iFile>>CPU_MainFreq>>CPU_CoreNum>>CPU_Power>>Memory>>HD>>ProtectGrade)
    {
        A.push_back({CPU_MainFreq,CPU_CoreNum,CPU_Power,Memory,HD,ProtectGrade});
    }
    iFile.close();
}
bool cmp(IPC a,IPC b)
{
    if(a.GetCPU().GetMainFreq()!=b.GetCPU().GetMainFreq())
    return a.GetCPU().GetMainFreq()<b.GetCPU().GetMainFreq();
    else
    return a.GetProtectGrade()<b.GetProtectGrade();
}
void SortIPC(vector<IPC> &A)
{
    sort(A.begin(),A.end(),cmp);
}
void IncreaseIPC(vector<IPC> &A)
{
    for(auto &it:A)
    {
        if(it.GetMemory()<=4)
        ++it;
    }
}
void OutputIPCFile(vector<IPC> &A,const char path[])
{
    ofstream oFile(path);
    for(auto item:A)
    {
            oFile<<item;
    }
    oFile.close();
}
int main()
{
vector<IPC> A;
ReadIPCFile("d:\\source.txt", A);
cout<<"当前工控机台数: "<<IPC::GetCounts()<<endl;
SortIPC(A);
IncreaseIPC(A);
cout<<"当前工控机台数: "<<IPC::GetCounts()<<endl;
OutputIPCFile(A,"d:\\res.txt");
IPC t1;
cout<<t1<<endl;
cout<<t1++<<endl;
cout<<t1<<endl;
cout<<"当前工控机台数"<<IPC::GetCounts()<<endl;
IPC t2(t1);
cout<<t2<<endl;
cout<<"当前工控机台数"<<IPC::GetCounts()<<endl;
system("pause");
return 0;
}