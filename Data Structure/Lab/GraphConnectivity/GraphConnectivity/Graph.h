#pragma once
#include<cstring>
#include<queue>
#include<iostream>
const int MaxSize = 100;
template<typename DataType>
class Graph
{
public:
	Graph(){}
	Graph(int num);
	~Graph() {};
	bool JudgeConnectivity(int u, int v);
	void AddEdge(int u, int v);
	void DeleteEdge(int u, int v);
	

private:
	//DataType X;
	int vertexNum ;
	int edge[MaxSize][MaxSize];
	bool st[MaxSize];
};
