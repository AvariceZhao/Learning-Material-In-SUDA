#include<iostream>
#include<set>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN],n,k;
long long ans=0;
void dfs(int u)
{	
	
	if(u>=n+1)
	{
		set<int>v;
		bool flag=true;
		for(int i=2;i<=n-1;i++)if(a[i-1]==a[i+1])flag=false;

		if(flag&&a[1]==a[n])
		{
			ans++;
		}
		
		return;
		
	}
	
	for(int i=1;i<=k;i++)
	{
		a[u]=i;
		if(a[u]!=a[u-1])
		dfs(u+1);
	}
	
}
int main()
{
	scanf("%d,%d",&n,&k);
	if(n<=0&&k<=0)
	{
		cout<<0<<endl;
		return 0;
	}
	dfs(1);	
	cout<<ans<<endl;
    return 0;
}