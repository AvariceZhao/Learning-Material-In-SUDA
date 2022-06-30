#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

// �˴�ΪCPerson��Ĵ��룬�����޸�
class CPerson
{
protected:
	string		m_name;					//����
	int			m_age;					//����
	string		m_gender;				//�Ա�
public:
	CPerson(string name, int age, string gender)		//���캯��
	{
		m_name		= name;
		m_age		= age;
		m_gender	= gender;
	}
	string getName() const				//��ȡ����
	{
		return m_name;
	}
	int getAge() const					//��ȡ����
	{
		return m_age;
	}
	string getGender() const			//��ȡ�Ա�
	{
		return m_gender;
	}
};

// �˴�����CTeacher��Ĵ�����������������
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
        out<<"����:"<<temp.getName()<<"\t"
        <<"����:"<<temp.getAge()<<"\t"
        <<"�Ա�"<<temp.getGender()<<"\t"
        <<"�γ�"<<temp.m_subject<<"\t"
        <<"����:"<<temp.m_teaching_age;
        return out;
    }
    int getTeachingAge()const{return m_teaching_age;}

};

// �˴�����readData����
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

// �˴�����showData����
void showData(vector<CTeacher> & myVect)
{   
    cout<<"==================================================================="<<endl;
    for(auto it:myVect)
    {
    cout<<it<<endl;    
    }
    cout<<"==================================================================="<<endl;
}

// �˴�����processData����
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

// ���²���Ϊmain�����������޸�
int main()
{
	vector<CTeacher> myVect;			//��������
	readData("teacher.txt", myVect);	//���ļ��ж�ȡ���ݵ�����
	showData(myVect);					//��ʾ��ȡ��������
	vector<CTeacher> myVectNew;			//��������
	processData(myVect, myVectNew);		//��myVect�еĶ���Ҫ����ӵ�myVectNew��
	showData(myVectNew);				//��ʾmyVectNew�����еĶ���
    system("pause");
	return 0;
}
