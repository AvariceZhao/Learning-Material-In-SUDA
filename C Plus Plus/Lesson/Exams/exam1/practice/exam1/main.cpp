#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int readInfo(const char filePath[],vector<string> &words)
{
	ifstream ifile;
	string word;
	ifile.open(filePath);
	if(ifile.fail())
	{
	ifile.close();
	return -1;//δ�ɹ��򿪷���-1 
	}
	else
	{
		while(ifile>>word)
		{
		words.push_back(word);//��ȡ���ʴ���word������ 
		}
		ifile.close();
		return 0;
	}


}
int delInfo(vector<string> &words)
{
	int delCount=0;
	vector<string>::iterator p=words.begin();//��������� 
	while(p!=words.end())
	{
		if((*p).size()<3||(*p).size()>8)
		p=words.erase(p),delCount++;//�������Ҫ����ɾ�������� 
		else
		p++;
	}
	return delCount;
}
int delInfo(vector<string> &words,char ch)
{
		int delCount=0;//�������� 
	vector<string>::iterator p=words.begin();
	while(p!=words.end())
	{
		if((*p).find(ch)<(*p).size())
		{
			p=words.erase(p);//ɾ�� 
			delCount++;//��ɾ�����м��� 
		}else
		p++;
		
	}
	return delCount;	
}
void showInfo(vector<string> &words,int cnt=5)//ͨ��������Ĭ��ֵ���п��� 
{
		int Count=0;//�жϵ�ǰ����˶��ٸ� 
		if(words.size()<10)//���С��10����ȫ����� 
		for(int i=0;i<words.size();i++)
		{
			cout<<setw(10)<<right<<words[i];
			Count++;
			if(Count%cnt==0)
			cout<<endl;//����ض���������л��� 
		}
		else
		{
			for(int i=0;i<10;i++)
			{
			cout<<setw(10)<<right<<words[i];
		
			if(Count%cnt==0)
				cout<<endl;//����ض���������л��� 
			}
		}
		
		
	
}
vector<string> filterInfo(vector<string> words)
{
	vector<string>ans;//��¼�� 
	for(int i=0;i<words.size();i++)
	{
		for(int j=0;j<words[i].size();j++)
		{
			if(!((words[i][j]>='A'&&words[i][j]<='Z')||(words[i][j]>='a'&&words[i][j]<='z')))//�ж��Ƿ��д�Сд��ĸ����ĵ��� 
			{
				ans.push_back(words[i]);//�������Ҫ������ӵ��������ﲢ�����˵��ʵı��� 
				break;
			}
		}
	}
	return ans;//���ؽ�� 
	
}
bool cmp(string word1,string word2)
{
	if(word1.size()!=word2.size())return word1.size()<word2.size();//�Ƚϳ��� 
	else
	{	// ȫ��ת��ΪСд��ĸ���бȽ� 
		for(int i=0;i<word1.size();i++)
			if(word1[i]>='A'&&word1[i]<='Z')
				word1[i]+=32;
		for(int i=0;i<word2.size();i++)
			if(word2[i]>='A'&&word2[i]<='Z')
				word2[i]+=32;
		return word1<word2;//�����ֵ�����бȽ� 
	}
}
void sortInfo(vector<string> &specialWords)
{
	sort(specialWords.begin(),specialWords.end(),cmp);//�Զ���cmp������������ 
}
void writeInfo(const char outPath[],vector<string> specialWords)
{
	ofstream ofile;
	ofile.open(outPath);
	int count=0;//���м�����ÿ���10���������һ�����з� 
	for(int i=0;i<specialWords.size();i++)
	{
		ofile<<specialWords[i]<<" ";
		count++;
		if(count%10==0)//ÿ���10�����л��� 
		ofile<<'\n';
	}
}
bool cmpFunc(pair<int,char> x,pair<int,char> y)
{
	if(x.first!=y.first)
	return x.first>y.first;
	else
	return x.second<y.second;
}
char getTopmostChar(vector<string> specialWords)
{
	pair<int,char>charCounts[255];//����pair�洢�ַ������� 
	for(int i=0;i<specialWords.size();i++)
		for(int j=0;j<specialWords[i].size();j++)
		{
			charCounts[specialWords[i][j]].first++;//���� 
			charCounts[specialWords[i][j]].second=specialWords[i][j];//�洢�ַ� 
		}
	sort(charCounts,charCounts+255,cmpFunc);//���ݳ��ִ�����ascii��ֵ�������� 
	return charCounts[0].second;
}
int main()
{
	vector<string> words;
	vector<string> specialWords;
	if (readInfo("d:\\info.txt", words) == -1)
	{
		cout << "��d:\\info.txt�ļ�ʧ��" << endl;
	}
	else
	{
		cout << "��ȡ��" << words.size() << "������" << endl;
	}
	cout << "ɾ���˳��ȴ���8��С��3�ĵ���" << delInfo(words) << "��" << endl;
	cout << "ɾ���˰����ַ�','�ĵ���" << delInfo(words,',') << "��" << endl;
	cout << "ɾ�����ǰ10�������ǣ�\n";
	showInfo(words, 6);
	specialWords = filterInfo(words);
	cout << "\nɸѡ��"<< specialWords.size()<<"�����ʣ�ǰ10�������ǣ�"<<endl;
	showInfo(specialWords);
	
	sortInfo(specialWords);
	cout << "\n������ǰ10�������ǣ�\n";
	showInfo(specialWords);
	writeInfo("d:\\result.txt", specialWords);
	char ch = getTopmostChar(specialWords);
	cout << "\nspecialWords�г��ִ��������ַ���" << ch << endl;

	return 0;
}

