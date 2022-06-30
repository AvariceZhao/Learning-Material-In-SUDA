/*******************************************
	ѧ�ţ�
	������
	�ֻ����룺
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
	int m_ID;		//����
	string m_Name;	//����
	int m_Sex;		//�Ա�	0����Ů��	1��������
	int m_Age;		//����

public:
	CWorker(int ID, string Name, int Sex, int Age)
	{
		if (Sex<0 || Sex>1)
		{
			cout<<"�Ա��ʼֵ"<<Sex<<"������Ҫ��"<<endl;
			exit(0);
		}
		if (Age<=0 )
		{
			cout<<"�����ʼֵ"<<Age<<"������Ҫ��"<<endl;
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
   int number = 0;  // ɾ������
	auto iter = myVect.begin();
	while (iter != myVect.end()) {  // ����ɾ��
		if (iter->GetAge() >= ageX && iter->GetGrade() <= gradeY) {  // ��������ɾ��
			iter = myVect.erase(iter);
			number++;
		}
		else {  // ��������������������
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
	
	cout<<"�ļ���ȡ��һ���� "<<a.size()<<" ��ǯ�����ݣ�"<<endl;
	DisplayData(a);

	InecData(a);

	c=DelData(a,55,2);	//��2������Ϊ���䣬��3������Ϊ�ȼ�
	cout<<endl<<"��1��ɾ����"<<c<<"��ǯ������"<<endl;

	c=DelData(a,"Tom");
	cout<<endl<<"��2��ɾ����"<<c<<"��ǯ������"<<endl;

	SortData(a);

	cout<<endl<<"�������̽�����һ���� "<<a.size()<<" ��ǯ�����ݣ�"<<endl;
	DisplayData(a);

	if (WriteData("d:\\res.txt",a)==0)
		return -1;
	cout<<endl<<"�ļ�����ɹ�"<<endl<<endl;
    system("pause");
}