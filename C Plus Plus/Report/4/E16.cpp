#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	char c;
	int cnt=0;
}cnts[27];
bool cmp(node x,node y)
{	if(x.cnt!=y.cnt)
	return x.cnt>y.cnt;
	else
	return x.c<y.c;
}
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	if(s[i]>='A'&&s[i]<='Z')
		s[i]+='a'-'A';
	for(int i=0;i<s.size();i++)
	{
	
		cnts[s[i]-'a'].cnt++;
		cnts[s[i]-'a'].c=s[i];
	}
	sort(cnts,cnts+26,cmp);
	for(int i=0;i<26;i++)
	{
		if(cnts[i].cnt==0)
		break;
		cout<<cnts[i].c<<" "<<cnts[i].cnt<<endl;	
	}
	return 0;
	
} 
