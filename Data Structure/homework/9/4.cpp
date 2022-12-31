#include<bits/stdc++.h>
using namespace std;
const int N=200;
struct Node
{
	int weight;
	int parent,lchild,rchild;
};
int n;
int w[N];
Node huf[N]; 
long long ans=0;
void select(Node huf[],int& min0,int &tmin,int k)
{

	min0=tmin=N-1;
	for(int i=1;i<=k;i++)
	{
	
		if(huf[i].parent==-1)
		{
		
			if(huf[i].weight<huf[min0].weight)
				{
					tmin=min0;
					min0=i;
				}
			else if (huf[i].weight>=huf[min0].weight&&huf[i].weight<huf[tmin].weight)
			{
				tmin=i;
			}
			
		}
	}

	
}
void Build(Node huf[])
{
	int k,i1,i2;
	for(int i=1;i<=2*n;i++)
	{
		huf[i].lchild=huf[i].rchild=huf[i].parent=-1;
	}

	for( k=n+1;k<=2*n-1;k++)
	{
	select(huf,i1,i2,k-1);

	
	huf[k].weight=huf[i1].weight+huf[i2].weight;
	ans+=huf[k].weight;
	huf[i1].parent=k;
	huf[i2].parent=k;
	huf[k].lchild=i1;
	huf[k].rchild=i2;
	

	}
	
	
	
	
}
int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>huf[i].weight;
	huf[N-1].weight=99999;
	Build(huf);
	cout<<ans<<endl;
}