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
	string		m_Lic;					//牌照
	string		m_Brand;			//品牌
	double		m_Dis;					//排量

public:
	CAutomobile (const string& Lic, const string& Brand, double Dis)		//构造函数
	{
		m_Lic		= Lic;
		m_Brand		= Brand;
		m_Dis	= Dis;
	}
	string GetLic()const	//获取牌照
	{
		return m_Lic;
	}
	string GetBrand()const	//获取品牌
	{
		return m_Brand;
	}
	double GetDis()const		//获取排量
	{
		return m_Dis;
	}
	void SetDis(double Dis)		//设置排量
	{
		m_Dis = Dis;
	}
};

/******* 请在下面编写你的代码 *******/
class CTruck:public CAutomobile
{
	private:
	double		m_Capacity;	//额定载货量，单位：吨
	int			m_Function;	//额定用途，1：一般   2：危险   3-渣土
	static int 	m_Counts;	//卡车总数
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
			out<<setw(6)<<right<<"一般";
		}
		else if(temp.GetFunction()==2)
		{
			out<<setw(6)<<right<<"危险";
		}
		else
		{
			out<<setw(6)<<right<<"渣土";
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
/******* 请在上面编写你的代码 *******/

int main()
{
	vector<CTruck> var;
	double aver_dis;

	var = ReadFile("d:\\trucks.txt");
	cout<<"文件中一共有"<<var.size()<<"条卡车数据"<<endl;

	cout<<"用途为一般的卡车如下:"<<endl;
	ShowTrucks(var,1);

	cout<<"品牌为奔驰的卡车如下:"<<endl;
	ShowTrucks(var,"奔驰");

	cout<<"吨位超过10吨的渣土车的平均排量为:"<<fixed<<setw(10)<<setprecision(2)<<GetAverDis(var, 3, 10.0)<<endl;

	CTruck t1;
	cout<<t1<<endl;
	cout<<t1++<<endl;
	cout<<t1<<endl;
	cout<<++t1<<endl;
	cout<<t1<<endl;

	CTruck t2(t1);
	cout<<t2<<endl;

	cout<<"卡车数量合计:"<<CTruck::GetCount()<<endl;
	system("pause");
	return 0;
}


