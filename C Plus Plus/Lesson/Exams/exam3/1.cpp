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
	double		m_Capacity;	//额定载货量，单位：吨
	int			m_Function;	//额定用途，1：一般   2：危险   3-渣土
	static int 	m_Counts;	//卡车总数
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
        if(temp.GetFunction()==1)out<<setw(6)<<right<<"一般"<<" ";
        else if (temp.GetFunction()==2)out<<setw(6)<<right<<"危险"<<" ";
        else out<<setw(6)<<right<<"渣土"<<" ";
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

