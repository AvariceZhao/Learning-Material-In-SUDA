//fw
#include<bits/stdc++.h>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define endl '\n'
#define il inline
#define pb push_back
#define fi first
#define se second
#define lc u<<1
#define rc u<<1|1
using namespace std;
typedef long long ll;
const int N=110;

struct url{//用结构体存储数据
	string path;
	string name;
}rule[N];
int n,m;
string checkNum(string &str)//判断是不是纯数字
{
	string res;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9')res+=str[i];
		else
		{
			res.clear();
			return res;
		}
	}
	int k=0;
	while(k+1<res.size()&&res[k]=='0')//去除前导零
		k++;
	return res.substr(k);
}

vector<string>get(string &path,string &str)
{
	vector<string>res(1);
	int i,j;

	for( i=1,j=1;i<path.size()&&j<str.size();)//双指针遍历
	{
		int u=i+1,v=j+1;

		while(u<path.size()&&path[u]!='/')u++;//找到中间字符
		while(v<str.size()&&str[v]!='/')v++;
		string a=path.substr(i,u-i),b=str.substr(j,v-j);//用substr取字符
	//分情况讨论
		if(a=="<str>")
		{
			res.push_back(b);
			i=u+1,j=v+1;
		}
		else if (a=="<int>")
		{
			auto t=checkNum(b);
			if(!t.empty())
			{
				res.push_back(t);
				i=u+1,j=v+1;
				
			}
			else 
			{
				res.clear();
				return res;
			}
		}
		else if(a=="<path>")
		{
			res.push_back(str.substr(j));
			return res;
		}
		else if (a!=b)
		{
			res.clear();
			return res;
		}
		else i=u+1,j=v+1;
	}
	if(i - path.size() != j - str.size()) res.clear();
	return res;
}
void work(string &str)
{
	for(int i=0;i<n;i++)
	{
		auto res=get(rule[i].path,str);
		if(res.size())
		{
			cout<<rule[i].name;
			for(int j=1;j<res.size();j++)
			{
				cout<<' '<<res[j];
			}
			cout<<endl;
			return;
		}
	}
	cout<<"404"<<endl;
}
int main()
{
  //ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>rule[i].path>>rule[i].name;
	}
	while(m--)
	{
		string t;
		cin>>t;
		work(t);
	}
  return 0;
}
