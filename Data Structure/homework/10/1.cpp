#include<iostream>
#include<cstring>
using namespace std;
const int MaxSize=100;
template<typename DataType>
class Graph
{	
public:
	Graph();
	~Graph(){};
	int Count();
private:
	int vertexNum,edgeNum;
	DataType vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	void DFT(int v,int st[]);
		
};
template<typename DataType>
Graph<DataType>::Graph()
{
	cin>>vertexNum;
	for(int i=1;i<=vertexNum;i++)
			for(int j=1;j<=vertexNum;j++)
				cin>>edge[i][j];
}
template<typename DataType>
int Graph<DataType>::Count()
{
	int ans=0;
	int st[MaxSize];
	memset(st,0,sizeof st);
	for(int i=1;i<=vertexNum;i++)
	{
		if(!st[i])
		{	ans++;
			DFT(i,st);
		}	
	}
	return ans;
}
template<typename DataType>
void Graph<DataType>::DFT(int v,int st[])
{
	st[v]=true;
	for(int i=1;i<=vertexNum;i++)
	{
		if(!st[i]&&edge[v][i])
		{
			DFT(i,st);
		}
	}
}
int main()
{

	Graph<int>G;
	cout<<G.Count()<<endl;
	return 0;
}
