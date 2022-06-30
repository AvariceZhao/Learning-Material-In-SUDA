#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;
const int N=1e5+5;
int n,vnum,k,TestNum; 
struct node{
    string id;
    double v[1000];
    string type;
  
}data[N],test[N];
struct hp{
	double distance;
	string type;
	  bool operator<(const hp &W)const{
	  return distance<W.distance;
	  }
};
double GetDistance(node a,node b)
{
	double res=0;
	for(int i=0;i<vnum;i++)
		res+=(a.v[i]-b.v[i])*(a.v[i]-b.v[i]);
	return sqrt(res);
}
void ReadDataInfo(const char path[],int num)
{
	ifstream infile;
	infile.open(path);
	char buff[256];
	for(int i=0;i<n;i++) 
	{	infile.getline(buff,256);
		stringstream is(buff);
		is>>data[i].id;
		for(int j=0;j<num;j++) 
			is>>data[i].v[j];
		is>>data[i].type;
	}
	infile.close();
	return;
}
void ReadTestInfo(const char path[],int num,int TestNum)
{
	ifstream infile;
	infile.open(path);
	char buff[256];
	for(int i=0;i<n;i++) 
	{	infile.getline(buff,256);
		stringstream is(buff);
		is>>test[i].id;
		for(int j=0;j<num;j++) 
			is>>test[i].v[j];
		is>>test[i].type;
	}
	infile.close();
	return;
}
void showData(int num)
{
		for(int i=0;i<num;i++)
	{
		cout<<test[i].id<<" ";
		for(int j=1;j<=4;j++)
			cout<<test[i].v[j]<<" ";
		cout<<test[i].type<<endl;
	}
}
bool classify(node data0,int k)
{
	priority_queue<hp>heap;
	for(int i=1;i<=n;i++)
	{
		double dis=GetDistance(data[i],data0);
		if(heap.size()<k)
		heap.push({dis,data[i].type});
		else
		{
			heap.push({dis,data[i].type});
			heap.pop();
			
		}
	}
	map<string,pair<string,int> >mp;
	while(heap.size())
	{
		auto t=heap.top();
	
		heap.pop();
		mp[t.type].second++;
		mp[t.type].first=t.type;
	}
	int MaxCnt=0;
	string ans;
	map<string,pair<string,int> >::iterator it=mp.begin();
	while(it!=mp.end())
	{	
	
		if((it->second).second>MaxCnt)
		{
			MaxCnt=(it->second).second;
			ans=(it->second).first;
		}
		it++;
		
	}

	return ans==data0.type;
	
}

int main()
{	
	cout<<"以此输入训练用数据条数、每组数据的维度"<<endl; 
    cin>>n>>vnum;//数据条数 
	ReadDataInfo("d:\\iris.txt",vnum); 
	cout<<"训练数据读入完成"<<endl;
	cout<<"请输入测试数据条数";
	cin>>TestNum;
	ReadTestInfo("d:\\test.txt",vnum,TestNum); 


	for(int tk=1;tk<=n;tk+=2)
	{
	int TrueNum=0;
	for(int i=0;i<TestNum;i++)
	{
		if(classify(test[i],tk))
		TrueNum++;
	}
	cout<<tk<<" "<<TrueNum*1.0/TestNum<<endl;
	}
	 
	

}