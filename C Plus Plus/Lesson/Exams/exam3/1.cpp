#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class CAutomobile
{
private:
	string		m_Lic;					//����
	string		m_Brand;			//Ʒ��
	double		m_Dis;					//����

public:
	CAutomobile (const string& Lic, const string& Brand, double Dis)		//���캯��
	{
		m_Lic		= Lic;
		m_Brand		= Brand;
		m_Dis	= Dis;
	}
	string GetLic()const	//��ȡ����
	{
		return m_Lic;
	}
	string GetBrand()const	//��ȡƷ��
	{
		return m_Brand;
	}
	double GetDis()const		//��ȡ����
	{
		return m_Dis;
	}
	void SetDis(double Dis)		//��������
	{
		m_Dis = Dis;
	}
};

/******* ���������д��Ĵ��� *******/
class CTruck:public CAutomobile
{
	double		m_Capacity;	//��ػ�������λ����
	int			m_Function;	//���;��1��һ��   2��Σ��   3-����
	static int 	m_Counts;	//��������
public:
	CTruck(string Lic="R00001",string Brand="BENZ",double Dis=5.0,int Function=1,double Capacity=20.0):CAutomobile(Lic,Brand,Dis)
	{
		m_Function=Function;
		m_Capacity=Capacity;
		m_Counts++;
	}
	CTruck(const CTruck &temp):CAutomobile(temp.GetLic(),temp.GetBrand(),temp.GetDis())
	{
		m_Capacity=temp.GetCapacity();
        m_Function=temp.GetFunction();
        m_Counts++;
	}
    ~CTruck()
    {
        m_Counts--;
    }
    double GetCapacity()const
    {
        return m_Capacity;
    }
    int GetFunction()const
    {
        return m_Function;
    }
    static int GetCount()
    {
        return m_Counts;
    }
    CTruck &operator++()
    {
        m_Capacity+=1.0;
        this->SetDis(this->GetDis()+1.0);
    }
    CTruck operator++(int)
    {   auto temp=*this;
        m_Capacity+=1.0;
        this->SetDis(this->GetDis()+1.0);
        return temp;
    }
    friend ostream &operator<<(ostream &out,const CTruck &temp)
    {
        out<<setw(10)<<right<<temp.GetLic()<<" "
        <<setw(10)<<right<<temp.GetBrand()<<" "
        <<setw(8)<<right<<fixed<<setprecision(1)<<temp.GetDis()<<" ";
        if(temp.GetFunction()==1)out<<setw(6)<<right<<"һ��"<<" ";
        else if (temp.GetFunction()==2)out<<setw(6)<<right<<"Σ��"<<" ";
        else out<<setw(6)<<right<<"����"<<" ";
        out<<setw(8)<<fixed<<setprecision(2)<<right<<temp.GetCapacity();
        return out;
    }
};
int CTruck::m_Counts=0;
vector<CTruck> ReadFile(const char path[])
{
    vector<CTruck>ans;
    ifstream ifile;
    ifile.open(path);
    string Lic,Brand;double Dis,Capacity;int Function;
    while(ifile>>Lic>>Brand>>Dis>>Function>>Capacity)
    {
        ans.push_back(CTruck(Lic,Brand,Dis,Function,Capacity));
    }
    return ans;
}
void ShowTrucks(vector<CTruck> &var,int t)
{
    for(auto it:var)
        if(it.GetFunction()==t)
            cout<<it<<endl;
}
void ShowTrucks(vector<CTruck> &var,string t)
{
    for(auto it:var)
        if(it.GetBrand()==t)
            cout<<it<<endl;
}
double GetAverDis(vector<CTruck> &var,int t,double num)
{
    double sum=0;
    int cnt=0;
    for(auto it:var)
    {
        if(it.GetFunction()==t&&it.GetCapacity()>=num)
        {
            sum+=it.GetDis();
            cnt++;
        }
    }
    return sum/cnt;
}
/******* ���������д��Ĵ��� *******/
int main()
{
	vector<CTruck> var;
	double aver_dis;

	var = ReadFile("d:\\trucks.txt");
	cout<<"�ļ���һ����"<<var.size()<<"����������"<<endl;

	cout<<"��;Ϊһ��Ŀ�������:"<<endl;
	ShowTrucks(var,1);

	cout<<"Ʒ��Ϊ���۵Ŀ�������:"<<endl;
	ShowTrucks(var,"����");

	cout<<"��λ����10�ֵ���������ƽ������Ϊ:"<<fixed<<setw(10)<<setprecision(2)<<GetAverDis(var, 3, 10.0)<<endl;

	CTruck t1;
	cout<<t1<<endl;
	cout<<t1++<<endl;
	cout<<t1<<endl;
	cout<<++t1<<endl;
	cout<<t1<<endl;

	CTruck t2(t1);
	cout<<t2<<endl;

	cout<<"���������ϼ�:"<<CTruck::GetCount()<<endl;
    system("pause");
	return 0;
}

