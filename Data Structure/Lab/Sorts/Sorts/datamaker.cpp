#include<iostream>
#include<random>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
mt19937 rnd(time(0));

int main()
{
	cout<<"开始生成数据"<<endl;
	int base=50;
	string s[3]={"order","reverse","random"};
	string path="D://data_";
	for(int i=1;i<=4;i++)
	{
		for(int j=0;j<3;j++)
		{
			string temp=s[j];
			string file_path=path+temp+"_"+to_string(base)+".txt";
			ofstream oFile(file_path);
			oFile<<base<<endl;
			vector<int>num;
			for(int k=1;k<=base;k++)
			{
				num.push_back(rnd());
			}
			if(j==0)
			{
				sort(num.begin(),num.end());
			}
			else if (j==1)
			{
				sort(num.begin(),num.end());
				reverse(num.begin(),num.end());
			}
			for(auto number:num)
				oFile<<number<<" ";
			oFile.close();
		}
		base*=10;
	}
	cout<<"数据生成完成"<<endl;
	return 0;
}
