#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void solve(int l1,int l2,int r1,int r2)
{
	int p=s1.find(s2[r2]);
	cout<<s2[r2];
	if(p-1>=l1)
		dfs(l1,p-1,r1,r1+p-1-l1);
	if(p+1<=l2)
		dfs(p+1,l2,r1+p-l1,r2-1);
}
int main()
{
	cin>>s1>>s2;
	solve(0,s1.length()-1,0,s2.length()-1);
} 

