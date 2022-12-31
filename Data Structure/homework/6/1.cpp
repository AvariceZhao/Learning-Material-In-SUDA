//fw
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<set>
using namespace std;
const int N=1e5+10;
struct node
{
	int stu,id,score;//学生，课程，成绩
};
vector<node>datas;
vector<node>new_data;
typedef pair<int,int>pii;
int scores[100][1000];
bool flag[100][1000];
bool cmp(node a,node b)
{
	if(a.stu!=b.stu)
	{
		return a.stu<b.stu;
	}
	return a.id<b.id;
}
void read()
{
	int a,b,c;
	//int cnt=0;
	memset(flag,0,sizeof flag);
	while(scanf("%d,%d,%d",&a,&b,&c)&&a!=-1)
	{
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(a>=10&&a<=99&&b>=100&&b<=999&&c>=0&&c<=100)
			{
				datas.push_back({a,b,c});
			
			}
	///		cnt++;
	//	if(cnt==9)break;
	}
//	string s;
//	getchar();
//	getline(cin,s);
//	cout<<s<<endl;
	// datas.push_back({12,302,84});
//	getline(cin,s);
//	cout<<s<<endl;
	// datas.push_back({23,302,84});
//	 int x;
	// cin>>x;
	
	for(auto i:datas)
	{
		int a=i.stu,b=i.id,c=i.score;
		scores[a][b]=max(scores[a][b],c);
		
	}
	for(auto i:datas)
	{		int a=i.stu,b=i.id,c=i.score;
		//cout<<a<<" "<<b<<" "<<scores[a][b]<<" "<<c<<endl;
		if(c==scores[a][b]&&!flag[a][b])
		{
		
			new_data.push_back({a,b,c});
			flag[a][b]=true;
		}
	}
	
	sort(new_data.begin(),new_data.end(),cmp);
	 for(auto i:new_data)
	 {		int a=i.stu,b=i.id,c=i.score;
		 cout<<a<<","<<b<<","<<c<<endl;
	}
	cout<<endl;
	
}
void get_class(int x)
{
	vector<pii>v;
	for(auto i:new_data)
	 {	int a=i.stu,b=i.id,c=i.score;
		 if(b==x)
		 v.push_back({c,a});
	}
	sort(v.begin(),v.end());
	int ans=v[0].first;
	for(auto i:new_data)
	 {	int a=i.stu,b=i.id,c=i.score;
		 if(c==ans&&b==x)
		 cout<<a<<","<<ans<<endl;
	}
	cout<<endl;
}
void get_stu(int x)
{
	for(auto i:new_data)
	 {	int a=i.stu,b=i.id,c=i.score;
		 if(a==x)
		 cout<<b<<","<<c<<endl;
	}
}
int main()
{
    read();
    
    int class_id,stu_id;
    cin>>class_id>>stu_id;
    get_class(class_id);
    get_stu(stu_id);
    return 0;
}