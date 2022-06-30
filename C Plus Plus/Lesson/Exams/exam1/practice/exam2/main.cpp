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
    	ifstream ifile;//打开文件 
        ifile.open(filePath);
        string Id,Subject;
        int Score;
        while(ifile>>Id>>Subject>>Score)//读入数据 
        {
                mark stu;//存储数据 
                stu.xh=Id;// 
                stu.kc=Subject;
                stu.cj=Score;
                marks.push_back(stu);//保存结果到vector中 


        }
}
void ShowData(vector <struct mark> &marks,int num=3)//设置默认参数 
{
    for(int i=0;i<min((int)marks.size(),num);i++)//打印前几条数据 
    {
        cout<<setw(15)<<left<<marks[i].xh;
        cout<<setw(10)<<left<<marks[i].kc;
        cout<<setw(8)<<right<<marks[i].cj;
        cout<<endl;
    }

}

int Filter(vector <struct mark> &marks) 
{
	vector<struct mark>::iterator p=marks.begin();//定义迭代器 
	int delCount=0;
	while(p!=marks.end())
	{
		if((*p).cj<0||(*p).cj>100)//不满足要求则删除 
		{
			p=marks.erase(p);//删除 
			delCount++;//计数 
			
		}else
		p++;
	}
	return delCount;//返回删除数量 
}
vector<struct student> FillData(vector <struct mark> &marks)
{

	map<string,student>stuInformation;//利用map存储学生信息 
	vector<struct student> ans;//存储函数需要返回的结果 
	for(int i=0;i<marks.size();i++)
	{	
		(stuInformation[marks[i].xh]).xh=marks[i].xh;//添加学号信息
		 
		if(marks[i].kc=="Math")//添加数学成绩 
		(stuInformation[marks[i].xh]).math=marks[i].cj;
		
		else if (marks[i].kc=="C++")//添加C++成绩 
		(stuInformation[marks[i].xh]).cplusplus=marks[i].cj;
		
		else
		(stuInformation[marks[i].xh]).english=marks[i].cj;//添加英语成绩 
	}
	
	map<string,student>::iterator p=stuInformation.begin();//定义迭代器遍历map 
	while(p!=stuInformation.end())
	{
		ans.push_back(p->second);//将map中数据存到vector中 
		p++;
	}
	return ans;//返回结果 
		
}

bool cmp(student stu1,student stu2)
{
	if(stu1.cplusplus+stu1.english+stu1.math!=stu2.cplusplus+stu2.english+stu2.math)
	return stu1.cplusplus+stu1.english+stu1.math>stu2.cplusplus+stu2.english+stu2.math;//按总分从高到低排序 
	else
	return stu1.xh<stu2.xh;//总分相同时按学号从低到高排序 
}
void SortData(vector<struct student>::iterator stuBegin,vector<struct student>::iterator stuEnd,bool cmp(student,student))
{
	sort(stuBegin,stuEnd,cmp);//调用sort函数排序 
}

void ShowData(vector<struct student> &stus,int num)
{
	for(int i=max(0,(int)stus.size()-num); i<=stus.size()-1;i++)//显示最后几条数据 
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
	for(int i=0;i<stus.size();i++)//输出数据到文件中 
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

		ReadFile("d:\\input.txt", marks); //读取文件的数据到marks

		cout << "数据总条数为：" << marks.size() << endl; //显示数据总数
		ShowData(marks,5);

		int count=Filter(marks);//删除其中不合法的数据
		cout << "合计删除了" << count << "条不合法成绩" << endl;

		vector<struct student> stus=FillData(marks);
		cout <<"汇总结果合计有"<< stus.size()<<"人"<< endl;
		
		SortData (stus.begin(), stus.end(), cmp);

		cout << "总分最低的5人信息为" << endl;
		ShowData(stus,5);

		WriteFile("d:\\res.txt",stus);

		return 0;
}

