/*******************************************
	学号：
	姓名：
	手机号码：
*******************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CWorker
{
private:
	int m_ID;		//工号
	string m_Name;	//姓名
	int m_Sex;		//性别	0代表女性	1代表男性
	int m_Age;		//年龄

public:
	CWorker(int ID, string Name, int Sex, int Age)
	{
		if (Sex<0 || Sex>1)
		{
			cout<<"性别初始值"<<Sex<<"不符合要求！"<<endl;
			exit(0);
		}
		if (Age<=0 )
		{
			cout<<"年龄初始值"<<Age<<"不符合要求！"<<endl;
			exit(0);
		}

		m_ID=ID;
		m_Name=Name;
		m_Sex=Sex;
		m_Age=Age;
	}

	string GetName()const
	{
		return m_Name;
	}

	int GetSex()const
	{
		return m_Sex;
	}

	int GetAge()const
	{
		return m_Age;
	}

	friend ostream& operator<<(ostream& Out, const CWorker& Obj)
	{
		Out<<right<<setw(5)<<Obj.m_ID;
		Out<<right<<setw(10)<<Obj.m_Name;
		Out<<right<<setw(5)<<Obj.m_Sex;
		Out<<right<<setw(6)<<Obj.m_Age;

		return Out;
	}
};
class CBenchWorker:public CWorker
{
    private:
    int m_grade;
    public:
    CBenchWorker(int id=0,string name="No Name",int sex=1,int age=18,int grade=1):CWorker(id,name,sex,age),m_grade(grade){};
    int GetGrade()const{return m_grade;}
    CBenchWorker &operator++()
    {
        m_grade=min(m_grade+1,5);
        return (*this);
    }
    friend ostream & operator<<(ostream &out,const CBenchWorker &temp)
    {
        out<<(CWorker)temp;
        out<<setw(5)<<right<<temp.m_grade;
        return out;

    }
};
int  ReadData(const char path[],vector<CBenchWorker> & a)
{
    ifstream iFile(path);
    if (iFile.fail())
    {
        return 0;
    }
    int id,sex,age,grade;
    string name;
    while(iFile>>id>>name>>sex>>age>>grade)
    {
        a.push_back({id,name,sex,age,grade});
    }
    iFile.close();
    return 1;
    
}
void DisplayData(vector<CBenchWorker> & a)
{
    for(auto it:a)
    {
        cout<<it<<endl;
    }
}
void InecData(vector<CBenchWorker>& myVect) {
	for (auto& worker : myVect) {
		++worker;
	}
}
int DelData(vector<CBenchWorker>& myVect, int ageX, int gradeY)
{
   int number = 0;  // 删除人数
	auto iter = myVect.begin();
	while (iter != myVect.end()) {  // 遍历删除
		if (iter->GetAge() >= ageX && iter->GetGrade() <= gradeY) {  // 符合条件删除
			iter = myVect.erase(iter);
			number++;
		}
		else {  // 不符合条件自增迭代器
			++iter;
		}
	}
	return number;
}
string getString(string x)
{
    auto temp=x;
    for(auto &chr:temp)
    {
        if(chr<'a')
        chr+='a'-'A';
    }
    return temp;

}

int DelData(vector<CBenchWorker> & a,string str)
{
      int count=0;
    auto it=a.begin();
    while(it!=a.end())
    {
        string s=getString((*it).GetName());
        if(s.find(getString(str))==string::npos)
        {
            it++;
        }
        else
        {
            it=a.erase(it);
            count++;
        }
    }
    return count;
}
bool cmp(CBenchWorker a,CBenchWorker b)
{
    if(a.GetSex()!=b.GetSex())
    return a.GetSex()<b.GetSex();
    else

    {
        if(a.GetSex()==1)
        {
            return a.GetGrade()<b.GetGrade();
        }
        else
        {
            return a.GetGrade()>b.GetGrade();
        }
    }
}
void SortData(vector<CBenchWorker> &a)
{
    sort(a.begin(),a.end(),cmp);
}
int WriteData(const char path[],vector<CBenchWorker> &a)
{
    ofstream oFile(path);
    if(oFile.fail())
    {
        return 0;
    }
    else
    {
        for(auto it:a)
        oFile<<it<<endl;
    }
}
int main()
{
	vector<CBenchWorker> a;
	int c;

	if (ReadData("d:\\workers.txt", a)==0)
		return -1;
	
	cout<<"文件读取后一共有 "<<a.size()<<" 条钳工数据："<<endl;
	DisplayData(a);

	InecData(a);

	c=DelData(a,55,2);	//第2个参数为年龄，第3个参数为等级
	cout<<endl<<"第1次删除了"<<c<<"个钳工数据"<<endl;

	c=DelData(a,"Tom");
	cout<<endl<<"第2次删除了"<<c<<"个钳工数据"<<endl;

	SortData(a);

	cout<<endl<<"上述流程结束后一共有 "<<a.size()<<" 条钳工数据："<<endl;
	DisplayData(a);

	if (WriteData("d:\\res.txt",a)==0)
		return -1;
	cout<<endl<<"文件保存成功"<<endl<<endl;
    system("pause");
}