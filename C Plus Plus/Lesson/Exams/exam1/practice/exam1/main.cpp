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
	return -1;//未成功打开返回-1 
	}
	else
	{
		while(ifile>>word)
		{
		words.push_back(word);//读取单词存入word向量中 
		}
		ifile.close();
		return 0;
	}


}
int delInfo(vector<string> &words)
{
	int delCount=0;
	vector<string>::iterator p=words.begin();//定义迭代器 
	while(p!=words.end())
	{
		if((*p).size()<3||(*p).size()>8)
		p=words.erase(p),delCount++;//如果满足要求则删除并计数 
		else
		p++;
	}
	return delCount;
}
int delInfo(vector<string> &words,char ch)
{
		int delCount=0;//计数变量 
	vector<string>::iterator p=words.begin();
	while(p!=words.end())
	{
		if((*p).find(ch)<(*p).size())
		{
			p=words.erase(p);//删除 
			delCount++;//对删除进行计数 
		}else
		p++;
		
	}
	return delCount;	
}
void showInfo(vector<string> &words,int cnt=5)//通过参数的默认值进行控制 
{
		int Count=0;//判断当前输出了多少个 
		if(words.size()<10)//如果小于10个则全部输出 
		for(int i=0;i<words.size();i++)
		{
			cout<<setw(10)<<right<<words[i];
			Count++;
			if(Count%cnt==0)
			cout<<endl;//输出特定个数后进行换行 
		}
		else
		{
			for(int i=0;i<10;i++)
			{
			cout<<setw(10)<<right<<words[i];
		
			if(Count%cnt==0)
				cout<<endl;//输出特定个数后进行换行 
			}
		}
		
		
	
}
vector<string> filterInfo(vector<string> words)
{
	vector<string>ans;//记录答案 
	for(int i=0;i<words.size();i++)
	{
		for(int j=0;j<words[i].size();j++)
		{
			if(!((words[i][j]>='A'&&words[i][j]<='Z')||(words[i][j]>='a'&&words[i][j]<='z')))//判断是否有大小写字母以外的单词 
			{
				ans.push_back(words[i]);//如果符合要求则添加到答案向量里并结束此单词的遍历 
				break;
			}
		}
	}
	return ans;//返回结果 
	
}
bool cmp(string word1,string word2)
{
	if(word1.size()!=word2.size())return word1.size()<word2.size();//比较长度 
	else
	{	// 全部转换为小写字母进行比较 
		for(int i=0;i<word1.size();i++)
			if(word1[i]>='A'&&word1[i]<='Z')
				word1[i]+=32;
		for(int i=0;i<word2.size();i++)
			if(word2[i]>='A'&&word2[i]<='Z')
				word2[i]+=32;
		return word1<word2;//根据字典序进行比较 
	}
}
void sortInfo(vector<string> &specialWords)
{
	sort(specialWords.begin(),specialWords.end(),cmp);//自定义cmp函数进行排序 
}
void writeInfo(const char outPath[],vector<string> specialWords)
{
	ofstream ofile;
	ofile.open(outPath);
	int count=0;//进行计数，每输出10个单词输出一个换行符 
	for(int i=0;i<specialWords.size();i++)
	{
		ofile<<specialWords[i]<<" ";
		count++;
		if(count%10==0)//每输出10个进行换行 
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
	pair<int,char>charCounts[255];//利用pair存储字符并计数 
	for(int i=0;i<specialWords.size();i++)
		for(int j=0;j<specialWords[i].size();j++)
		{
			charCounts[specialWords[i][j]].first++;//计数 
			charCounts[specialWords[i][j]].second=specialWords[i][j];//存储字符 
		}
	sort(charCounts,charCounts+255,cmpFunc);//根据出现次数和ascii码值进行排序 
	return charCounts[0].second;
}
int main()
{
	vector<string> words;
	vector<string> specialWords;
	if (readInfo("d:\\info.txt", words) == -1)
	{
		cout << "打开d:\\info.txt文件失败" << endl;
	}
	else
	{
		cout << "读取到" << words.size() << "个单词" << endl;
	}
	cout << "删除了长度大于8和小于3的单词" << delInfo(words) << "个" << endl;
	cout << "删除了包含字符','的单词" << delInfo(words,',') << "个" << endl;
	cout << "删除后的前10个单词是：\n";
	showInfo(words, 6);
	specialWords = filterInfo(words);
	cout << "\n筛选出"<< specialWords.size()<<"个单词，前10个单词是："<<endl;
	showInfo(specialWords);
	
	sortInfo(specialWords);
	cout << "\n排序后的前10个单词是：\n";
	showInfo(specialWords);
	writeInfo("d:\\result.txt", specialWords);
	char ch = getTopmostChar(specialWords);
	cout << "\nspecialWords中出现次数最多的字符是" << ch << endl;

	return 0;
}

