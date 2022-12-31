#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#define MaxSize 105
struct Edge {
	int u, v, w;
	bool operator <(const Edge& E)
	{
		return w < E.w;
	}
};
class SocialGraph
{
public:
	SocialGraph();
	~SocialGraph(){};
	std::string GetName(int i);
	std::string ShortestPath(int start, int end);
	void PeopleCanKnow(int p);
	bool judgeConnect();
	void addEdge(int u, int v);
	void deleteEdge(int u, int v);
	void addPeople(std::string name);
	void deletePeople(int u);
	void getVDCC_EDCC();
private:
	std::string vertexName[MaxSize];
	int edge[MaxSize][MaxSize];
	int vertexNum;
	int RealNum;
	int GetMin(int d[]);
	int times = 1;
	int dfn[MaxSize], low[MaxSize], fa[MaxSize];
	bool is_bridge[MaxSize][MaxSize];
	bool is_cut[MaxSize];
	void DCC_DFS(int x);

};