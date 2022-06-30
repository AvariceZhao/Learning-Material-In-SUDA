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
	private:
	double		m_Capacity;	//��ػ�������λ����
	int			m_Function;	//���;��1��һ��   2��Σ��   3-����
	static int 	m_Counts;	//��������
	public:
	CTruck(string lic="R00001",string band="BENZ",double dis=5.0,int function=1,double capacity=20.0):CAutomobile(lic,band,dis),m_Function(function),m_Capacity(capacity){m_Counts+=1;}
	CTruck(const CTruck & temp):CAutomobile(temp.GetLic(),temp.GetBrand(),temp.GetDis()),m_Capacity(temp.m_Capacity),m_Function(temp.m_Function){m_Counts+=1;}
	~CTruck(){m_Counts--;}
	double GetCapacity()const{return m_Capacity;}
	int GetFunction()const{return m_Function;}
	static int GetCount(){return m_Counts;}
	CTruck & operator++()
	{
		m_Capacity+=1.0;
		CAutomobile::SetDis((CAutomobile::GetDis())+1.0);
		return (*this);
	}
	CTruck  operator++(int)
	{	auto temp=(*this);
		m_Capacity+=1.0;
		CAutomobile::SetDis((CAutomobile::GetDis())+1.0);
		return temp;
	}
	friend ostream & operator<<(ostream &out,const CTruck temp)
	{
		out<<right<<setw(10)<<temp.GetLic()
		<<setw(10)<<right<<temp.GetBrand()
		<<setw(8)<<fixed<<setprecision(1)<<right<<temp.GetDis();
		if(temp.GetFunction()==1)
		{
			out<<setw(6)<<right<<"һ��";
		}
		else if(temp.GetFunction()==2)
		{
			out<<setw(6)<<right<<"Σ��";
		}
		else
		{
			out<<setw(6)<<right<<"����";
		}
		out<<setw(8)<<fixed<<setprecision(2)<<temp.m_Capacity;
		return out;
	}



}; 
int CTruck::m_Counts=0;
vector<CTruck> ReadFile(const char path[])
{
	vector<CTruck> ans;
	ifstream iFile(path);
	string lic, band;
	double dis,capacity;
	int function;
	while(iFile>>lic>>band>>dis>>function>>capacity)
	{
		ans.push_back({lic,band,dis,function,capacity});
	}
	return ans;
}
void ShowTrucks(vector<CTruck> &var,int x)
{
	for(auto it:var)
	{
		if(it.GetFunction()==x)
		{
			cout<<it<<endl;
		}
	}
}
void ShowTrucks(vector<CTruck> &var,string x)
{
	for(auto it:var)
	{
		if(it.GetBrand()==x)
		{
			cout<<it<<endl;
		}
	}
}
double GetAverDis(vector<CTruck> &var,double x,int y)
{
	double ans=0;
	int count=0;
	for(auto i:var)
	{
		if(i.GetCapacity()>x&&i.GetFunction()==y)
		{
			ans+=i.GetDis();
			count++;
		}
	}
	return ans/count;

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


