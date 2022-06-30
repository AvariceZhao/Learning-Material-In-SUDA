#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
class CPU
{
private:
double m_MainFreq; //��Ƶ����λ GHz
int m_CoreNum; //������
double m_Power; //���ʣ���λ��W
public:
CPU(double MainFreq, int CoreNum, double Power);
double GetMainFreq(void)const; //��ȡ��Ƶ
CPU& operator++(); //ǰ��������Ƶ�� 0.1���������� 2�����ʼ� 1.0
CPU operator++(int); //������������ͬ��
friend ostream& operator<<(ostream& Out, const CPU& Obj); //��� CPU �Ĳ�����
//��Ƶռ 6 �У�С�����ֱ��� 2 λ�������
//������ռ 3 �У������
//����ռ 6 �У�С�����ֱ��� 1 λ�������
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
int m_Memory; //�ڴ���������λ��G
int m_HD; //Ӳ����������λ��G
public:
Computer(double CPU_MainFreq, int CPU_CoreNum, double CPU_Power, int Memory, int HD);
CPU GetCPU(void)const; //��ȡ CPU ����
double GetMemory(void)const; //��ȡ�ڴ�����
Computer& operator++(); //ǰ������CPU ������������ͬ CPU �࣬�ڴ����� 4G��Ӳ������ 128G
Computer operator++(int); //������������ͬ��
friend ostream& operator<<(ostream& Out, const Computer& Obj);
//CPU �������ݵ���������� CPU ���ж�����ͬ
//�ڴ�����ռ 6 �У������
//Ӳ������ռ 8 �У������
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
int m_ProtectGrade; //�����ȼ�
static int m_Counts; //���ػ�����
public:
IPC(double CPU_MainFreq=3.7, int CPU_CoreNum=6, double CPU_Power=95.0, int Memory=16, 
int HD=512, int ProtectGrade=65);
IPC(const IPC& Obj);
double GetProtectGrade(void)const; //��ȡ�����ȼ�
static int GetCounts(void); //��ȡ��ǰ���ػ�����
IPC& operator++(); //ǰ������Computer ������������ͬ�ϣ������ȼ��� 1
IPC operator++(int); //������������ͬ��
friend ostream& operator<<(ostream& Out, const IPC& Obj);
//Computer �������ݵ���������� Computer ���ж�����ͬ
//�����ȼ�ռ 5 �У������
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
cout<<"��ǰ���ػ�̨��: "<<IPC::GetCounts()<<endl;
SortIPC(A);
IncreaseIPC(A);
cout<<"��ǰ���ػ�̨��: "<<IPC::GetCounts()<<endl;
OutputIPCFile(A,"d:\\res.txt");
IPC t1;
cout<<t1<<endl;
cout<<t1++<<endl;
cout<<t1<<endl;
cout<<"��ǰ���ػ�̨��"<<IPC::GetCounts()<<endl;
IPC t2(t1);
cout<<t2<<endl;
cout<<"��ǰ���ػ�̨��"<<IPC::GetCounts()<<endl;
system("pause");
return 0;
}