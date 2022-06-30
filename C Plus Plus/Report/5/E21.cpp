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
	
	if(File.fail())//��ʧ�� 
		return -1;
	
	int Lines=0;
	char Buff[256];
	
	while(File.getline(Buff,256))//���ж�ȡ 
	{
		stringstream is(Buff);
		string temp;
		
		vector<string> tmp;
		
		while(is>>temp)
			tmp.push_back(temp);//�洢���ʵ���ʱ���� 
		
		Words.push_back(tmp);//�洢���е��� 
		Lines++;
	}

	File.close();
		
		
}
double Value(string s)//���㵥������ֵ 
{
	double res=0;
	for(int i=0;i<s.size();i++)
		res+=s[i];
	return res/s.size(); //��������ֵ 
}

bool cmp(Data a,Data b)
{
	return a.value>b.value;
}
vector<Data> GetValue(vector<vector<string>> &Words)
{
	vector<Data>Ans;
	for(auto Vec:Words)//��ȡÿ�е���
	{
		vector<Data> Temp;
		for(int i=0;i<Vec.size();i++)//���㱾��Value 
			Temp.push_back({Vec[i],Value(Vec[i])});
		
		sort(Temp.begin(),Temp.end(),cmp);//������ֵ���� 
		
		cout<<Temp[0].word<<" "<<fixed<<setprecision(3)<<Temp[0].value<<endl;//�������ֵ���ĵ��� 
		
		Ans.push_back(Temp[0]);//�洢��������ֵ���ĵ��� 
		
	}
	return Ans;
}
void WriteInfo(const char FilePath[],vector<Data> &Value)
{
	ofstream File;
	
	File.open(FilePath);
	
	for(auto data:Value)//��ȡ֮ǰ����õ�ÿ������ֵ���ĵ��� 
		File<<data.word<<" "<<fixed<<setprecision(3)<<data.value<<endl;//��� 
	File.close();
	
}
int main()
{	


	vector<vector<string>>Words;
	vector<Data> Value;
	
	if(ReadInfo("C:\\data\\data.txt",Words)==-1)
	{
		cout<<"��data.txt�ļ�ʧ��"<<endl;
		return 0;
	}
	Value=GetValue(Words);
	
	WriteInfo("C:\\data\\wordValue.txt",Value);
	
	return 0;
	
	
}
