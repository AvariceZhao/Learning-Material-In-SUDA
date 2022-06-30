#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

// 此处为CPerson类的代码，不得修改
class CPerson
{
protected:
	string		m_name;					//姓名
	int			m_age;					//年龄
	string		m_gender;				//性别
public:
	CPerson(string name, int age, string gender)		//构造函数
	{
		m_name		= name;
		m_age		= age;
		m_gender	= gender;
	}
	string getName() const				//获取姓名
	{
		return m_name;
	}
	int getAge() const					//获取年龄
	{
		return m_age;
	}
	string getGender() const			//获取性别
	{
		return m_gender;
	}
};

// 此处插入CTeacher类的代码和所需的其它代码
class CTeacher:public CPerson
{
    private:
    string m_subject;
    int m_teaching_age;
    public:
    CTeacher(string name,int age,string gender,string subject,int teachingAge):CPerson(name,age,gender),m_subject(subject),m_teaching_age(teachingAge){};
    CTeacher operator++(int)
    {
        auto t=(*this);
        m_teaching_age+=1;
        return t;
    }
    friend ostream & operator<<(ostream &out,const CTeacher &temp)
    {
        out<<"姓名:"<<temp.getName()<<"\t"
        <<"年龄:"<<temp.getAge()<<"\t"
        <<"性别"<<temp.getGender()<<"\t"
        <<"课程"<<temp.m_subject<<"\t"
        <<"教龄:"<<temp.m_teaching_age;
        return out;
    }
    int getTeachingAge()const{return m_teaching_age;}

};

// 此处插入readData函数
void readData(const char path[],vector<CTeacher> & myVect)
{
    ifstream iFile(path);
    string name,subject,gender;
    int age,teachingAge;
    while(iFile>>name>>age>>gender>>subject>>teachingAge)
    {
        myVect.push_back({name,age,gender,subject,teachingAge});
    }
    iFile.close();
}

// 此处插入showData函数
void showData(vector<CTeacher> & myVect)
{   
    cout<<"==================================================================="<<endl;
    for(auto it:myVect)
    {
    cout<<it<<endl;    
    }
    cout<<"==================================================================="<<endl;
}

// 此处插入processData函数
void processData(vector<CTeacher> & myVect,vector<CTeacher> & myVectNew)
{
    for(auto &it:myVect)
    {
        it++;
        if(it.getTeachingAge()>=30)
        {
            myVectNew.push_back(it);
        }
    }
}

// 以下部分为main函数，不得修改
int main()
{
	vector<CTeacher> myVect;			//创建向量
	readData("teacher.txt", myVect);	//从文件中读取数据到向量
	showData(myVect);					//显示读取到的数据
	vector<CTeacher> myVectNew;			//创建向量
	processData(myVect, myVectNew);		//将myVect中的对象按要求添加到myVectNew中
	showData(myVectNew);				//显示myVectNew向量中的对象
    system("pause");
	return 0;
}
