#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int MaxSize=100;
vector<int>path;
template<typename DataType>
class Graph
{	
public:
	Graph();
	~Graph(){};
	//	int Count();
	void Path(int v);
private:
	int vertexNum,edgeNum;
	DataType vertex[MaxSize];
	int edge[MaxSize][MaxSize]={{0,1,0,0,0,1,0,0,0},
		{1,0,1,0,0,0,0,0,0},
		{0,1,0,1,0,1,0,0,0},
		{0,0,1,0,0,0,0,0,1},
		{0,0,0,0,0,1,1,0,1},
		{1,0,1,0,1,0,1,1,0},
		{0,0,0,0,1,1,0,1,0},
		{0,0,0,0,0,1,1,0,0},
		{0,0,0,1,1,0,0,0,0}};
	void DFT(int v,int st[],int num);
	
};
template<typename DataType>
Graph<DataType>::Graph()
{
	vertexNum=8;
}
//template<typename DataType>
//int Graph<DataType>::Count()
//{
//	int ans=0;
//	int st[MaxSize];
//	memset(st,0,sizeof st);
//	for(int i=1;i<=vertexNum;i++)
//	{
//		if(!st[i])
//		{	ans++;
//			DFT(i,st);
//		}	
//	}
//	return ans;
//}
template<typename DataType>
void Graph<DataType>::Path(int v)
{
	int st[9];
	memset(st,0,sizeof st);
	DFT(v,st,0);
}
template<typename DataType>
void Graph<DataType>::DFT(int v,int st[],int num)
{
	
	
	st[v]=1;
	path.push_back(v);
	if(num==8)
	{
		cout<<"[";
		for(int i=0;i<=8;i++)
		{
			if(i)
			{
				cout<<", "<<path[i];
			}
			else
				cout<<path[i];
		}
		cout<<"]";
		cout<<endl;
	}
	for(int i=0;i<=8;i++)
	{
		if(!st[i]&&edge[v][i])
		{
			DFT(i,st,num+1);
		}
	}
	st[v]=0;
	path.pop_back();
	
}
int main()
{
	
	Graph<int>G;
	int x;
	cin>>x;
	
	G.Path(x);
	return 0;
}
