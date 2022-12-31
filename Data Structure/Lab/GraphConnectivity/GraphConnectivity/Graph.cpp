#include"Graph.h"
template<typename DataType>
Graph<DataType>::Graph(int num)
{
	vertexNum = num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			edge[i][j] = (i == j);
}
template<typename DataType>
void Graph<DataType>::AddEdge(int u, int v)
{
	edge[u][v] = edge[v][u] = 1;
}
template<typename DataType>
void Graph<DataType>::DeleteEdge(int u, int v)
{
	edge[u][v] = edge[v][u] = 0;
}
template<typename DataType>
bool Graph<DataType>::JudgeConnectivity(int u, int v)
{
	if (u == v)return true;
	memset(st, 0, sizeof st);
	std::queue<int>Q;
	Q.push(u); st[u] = 1;
	while (Q.size())
	{
		auto head = Q.front(); Q.pop();
		for (int i = 1; i <= vertexNum; i++)
		{
			if (edge[head][i] && !st[i])
				if (i == v)return true;
				else
				{
					Q.push(i);
					st[i] = 1;
				}
		}
	}
	return false;
}
template Graph<int>;