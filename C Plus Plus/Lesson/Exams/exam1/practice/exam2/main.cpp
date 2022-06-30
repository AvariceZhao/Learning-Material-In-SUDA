#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<map>
using namespace  std;
struct mark

{
		string xh;//??
		string kc;//????
		int    cj;//??
};

struct student
{
		string xh;		//??
		int	math;		//????
		int english;		//????
		int cplusplus;	//C++??
};
void ReadFile(const char filePath[],	vector <struct mark> &marks)
{
    	ifstream ifile;//���ļ� 
        ifile.open(filePath);
        string Id,Subject;
        int Score;
        while(ifile>>Id>>Subject>>Score)//�������� 
        {
                mark stu;//�洢���� 
                stu.xh=Id;// 
                stu.kc=Subject;
                stu.cj=Score;
                marks.push_back(stu);//��������vector�� 


        }
}
void ShowData(vector <struct mark> &marks,int num=3)//����Ĭ�ϲ��� 
{
    for(int i=0;i<min((int)marks.size(),num);i++)//��ӡǰ�������� 
    {
        cout<<setw(15)<<left<<marks[i].xh;
        cout<<setw(10)<<left<<marks[i].kc;
        cout<<setw(8)<<right<<marks[i].cj;
        cout<<endl;
    }

}

int Filter(vector <struct mark> &marks) 
{
	vector<struct mark>::iterator p=marks.begin();//��������� 
	int delCount=0;
	while(p!=marks.end())
	{
		if((*p).cj<0||(*p).cj>100)//������Ҫ����ɾ�� 
		{
			p=marks.erase(p);//ɾ�� 
			delCount++;//���� 
			
		}else
		p++;
	}
	return delCount;//����ɾ������ 
}
vector<struct student> FillData(vector <struct mark> &marks)
{

	map<string,student>stuInformation;//����map�洢ѧ����Ϣ 
	vector<struct student> ans;//�洢������Ҫ���صĽ�� 
	for(int i=0;i<marks.size();i++)
	{	
		(stuInformation[marks[i].xh]).xh=marks[i].xh;//���ѧ����Ϣ
		 
		if(marks[i].kc=="Math")//�����ѧ�ɼ� 
		(stuInformation[marks[i].xh]).math=marks[i].cj;
		
		else if (marks[i].kc=="C++")//���C++�ɼ� 
		(stuInformation[marks[i].xh]).cplusplus=marks[i].cj;
		
		else
		(stuInformation[marks[i].xh]).english=marks[i].cj;//���Ӣ��ɼ� 
	}
	
	map<string,student>::iterator p=stuInformation.begin();//�������������map 
	while(p!=stuInformation.end())
	{
		ans.push_back(p->second);//��map�����ݴ浽vector�� 
		p++;
	}
	return ans;//���ؽ�� 
		
}

bool cmp(student stu1,student stu2)
{
	if(stu1.cplusplus+stu1.english+stu1.math!=stu2.cplusplus+stu2.english+stu2.math)
	return stu1.cplusplus+stu1.english+stu1.math>stu2.cplusplus+stu2.english+stu2.math;//���ִܷӸߵ������� 
	else
	return stu1.xh<stu2.xh;//�ܷ���ͬʱ��ѧ�Ŵӵ͵������� 
}
void SortData(vector<struct student>::iterator stuBegin,vector<struct student>::iterator stuEnd,bool cmp(student,student))
{
	sort(stuBegin,stuEnd,cmp);//����sort�������� 
}

void ShowData(vector<struct student> &stus,int num)
{
	for(int i=max(0,(int)stus.size()-num); i<=stus.size()-1;i++)//��ʾ��������� 
	{
		cout<<setw(15)<<left<<stus[i].xh;
		cout<<setw(5)<<right<<stus[i].math;
		cout<<setw(5)<<right<<stus[i].english;
		cout<<setw(5)<<right<<stus[i].cplusplus;
		cout<<endl;
		
	}
}

void WriteFile(const char filePath[],vector<struct student> &stus)
{
	ofstream ofile;
	ofile.open(filePath);
	for(int i=0;i<stus.size();i++)//������ݵ��ļ��� 
	{
		ofile<<setw(15)<<left<<stus[i].xh;
		ofile<<setw(5)<<right<<stus[i].math;
		ofile<<setw(5)<<right<<stus[i].english;
		ofile<<setw(5)<<right<<stus[i].cplusplus;
		ofile<<endl;
	}
}
int main()
{
		vector <struct mark> marks;

		ReadFile("d:\\input.txt", marks); //��ȡ�ļ������ݵ�marks

		cout << "����������Ϊ��" << marks.size() << endl; //��ʾ��������
		ShowData(marks,5);

		int count=Filter(marks);//ɾ�����в��Ϸ�������
		cout << "�ϼ�ɾ����" << count << "�����Ϸ��ɼ�" << endl;

		vector<struct student> stus=FillData(marks);
		cout <<"���ܽ���ϼ���"<< stus.size()<<"��"<< endl;
		
		SortData (stus.begin(), stus.end(), cmp);

		cout << "�ܷ���͵�5����ϢΪ" << endl;
		ShowData(stus,5);

		WriteFile("d:\\res.txt",stus);

		return 0;
}

