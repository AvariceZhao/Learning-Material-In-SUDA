#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;
struct Data{
	string word;
	double value;
};
int ReadInfo(const char FilePath[],	vector<vector<string>> &Words)
{
	ifstream File;
	File.open(FilePath);
	
	if(File.fail())//打开失败 
		return -1;
	
	int Lines=0;
	char Buff[256];
	
	while(File.getline(Buff,256))//按行读取 
	{
		stringstream is(Buff);
		string temp;
		
		vector<string> tmp;
		
		while(is>>temp)
			tmp.push_back(temp);//存储单词到临时向量 
		
		Words.push_back(tmp);//存储整行单词 
		Lines++;
	}

	File.close();
		
		
}
double Value(string s)//计算单词重心值 
{
	double res=0;
	for(int i=0;i<s.size();i++)
		res+=s[i];
	return res/s.size(); //返回重心值 
}

bool cmp(Data a,Data b)
{
	return a.value>b.value;
}
vector<Data> GetValue(vector<vector<string>> &Words)
{
	vector<Data>Ans;
	for(auto Vec:Words)//读取每行单词
	{
		vector<Data> Temp;
		for(int i=0;i<Vec.size();i++)//计算本行Value 
			Temp.push_back({Vec[i],Value(Vec[i])});
		
		sort(Temp.begin(),Temp.end(),cmp);//按重心值排序 
		
		cout<<Temp[0].word<<" "<<fixed<<setprecision(3)<<Temp[0].value<<endl;//输出重心值最大的单词 
		
		Ans.push_back(Temp[0]);//存储本行重心值最大的单词 
		
	}
	return Ans;
}
void WriteInfo(const char FilePath[],vector<Data> &Value)
{
	ofstream File;
	
	File.open(FilePath);
	
	for(auto data:Value)//读取之前计算好的每行重心值最大的单词 
		File<<data.word<<" "<<fixed<<setprecision(3)<<data.value<<endl;//输出 
	File.close();
	
}
int main()
{	


	vector<vector<string>>Words;
	vector<Data> Value;
	
	if(ReadInfo("C:\\data\\data.txt",Words)==-1)
	{
		cout<<"打开data.txt文件失败"<<endl;
		return 0;
	}
	Value=GetValue(Words);
	
	WriteInfo("C:\\data\\wordValue.txt",Value);
	
	return 0;
	
	
}
