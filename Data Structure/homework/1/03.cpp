// Problem: P6191 [USACO09FEB]Bulls And Cows S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6191
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2022-08-29 14:35:11
// 
// Powered by CP Editor (https://cpeditor.org)

//fw
#include<iostream>
using namespace std;
const int MOD=5000011;
const int N=1e5+10;
int bull[N],cow[N],n,k;
int main()
{
    cin>>n>>k;
    cow[1]=1;bull[1]=1;
    for(int i=2;i<=n;i++)
    {
    		cow[i]=(cow[i-1]+bull[i-1])%5000011;
    	if(i>k+1)
    	{
    		bull[i]=(bull[i-k-1]+cow[i-k-1])%5000011;
    	}
    	else
    	{
    		bull[i]=1;
    	}
    }
    cout<<(bull[n]+cow[n])%MOD;
    return 0;
}