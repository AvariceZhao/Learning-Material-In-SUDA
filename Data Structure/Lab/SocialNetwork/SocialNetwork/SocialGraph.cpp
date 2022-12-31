#include"SocialGraph.h"
#include"UnionSet.h"
#include<cstring>
#include<vector>
SocialGraph::SocialGraph()
{
	memset(edge, 0x3f, sizeof edge);
	std::cout << "Input the number of people in the socialnetwork:";
	std::cin >> vertexNum;
	RealNum = vertexNum;
	if (vertexNum > MaxSize)
	{
		std::cout << "The number is too large" << std::endl;
		exit(0);
	}
	std::cout << "Input the name of people:";
	for (int i = 0; i < vertexNum; i++)std::cin >> vertexName[i];
	std::cout << "People's id is numbered from 0 to " << vertexNum - 1 << std::endl;
	for (int i = 0; i < vertexNum; i++)
	{
		int num, friend_;
		std::cout << "Input the number of " << vertexName[i] << "'s friends:";
		std::cin >> num;
		std::cout << vertexName[i] << "'s friends are (id):";
		for (int j = 0; j < num; j++)
		{
			std::cin >> friend_;
			edge[i][friend_] = edge[friend_][i] = 1;
		}
		std::cout << std::endl;
	}
}
std::string SocialGraph::GetName(int i)
{
	return vertexName[i];
}
std::string SocialGraph::ShortestPath(int start, int end)
{
	
	if (start >= vertexNum || start < 0 || end >= vertexNum || end < 0)
	{
		std::cout << "Out of range" << std::endl;
		return "";
	}
	if (start == end)
		return GetName(start) + ">" + GetName(end);
	int dist[MaxSize];
	std::string path[MaxSize];
	for (int i = 0; i < vertexNum; i++)
	{
		dist[i] = edge[start][i];
		if (dist[i] == 1)	path[i] = vertexName[start] + ">" + vertexName[i];
		else path[i] = "";
	}
	for (int num = 1; num < vertexNum; num++)
	{
		int k = GetMin(dist);
		for(int i=0;i<vertexNum;i++)
			if (dist[i] > dist[k] + edge[k][i])
			{
				dist[i] = dist[k] + edge[k][i];
				path[i] = path[k] + ">" + vertexName[i];
			}
	dist[k] = 0;
	}
	return path[end];
}
int SocialGraph::GetMin(int d[])
{
	int index = 0, minNum = MaxSize;
	for (int i = 0; i < vertexNum; i++)
		if (d[i] != 0 && d[i] < minNum)
			minNum = d[i], index = i;
	return index;
}

void SocialGraph::PeopleCanKnow(int u)
{
	if (u >= vertexNum || u < 0)
	{
		std::cout << "Out of range" << std::endl;
		return;
	}

	int tempEdge[MaxSize][MaxSize]{};
	memset(tempEdge, 0, sizeof tempEdge);
	for (int k = 0; k < vertexNum; k++)
		for (int   i = 0; i < vertexNum; i++)
			for (int j = 0; j < vertexNum; j++)
				tempEdge[i][j] |= (edge[i][k]==1) * (edge[k][j]==1);
	for (int i = 0; i < vertexNum; i++)
		if (tempEdge[u][i] && u != i&&edge[u][i]!=1)
			std::cout << vertexName[i] << " ";
	std::cout << std::endl;
	return;
}
bool SocialGraph::judgeConnect()
{
	std::vector<Edge>Edges;
	
//	std::cout << "vertexnum" << vertexNum <<"RealNum"<<RealNum << std::endl;
	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < i; j++)
			if (edge[i][j] == 1)
			{
				Edges.push_back({ i,j,1 });
		//	std::cout << "edge:" << i << " " << j << std::endl;
			}
	UnionSet::init(vertexNum);
	int DisConnect = RealNum;
	
	for (int i = 0; i < (int)Edges.size(); i++)
	{
	
		int a = Edges[i].u, b = Edges[i].v;
	//	std::cout << a << " " << b <<" ";
		if (!UnionSet::same(a,b))
		{
			UnionSet::merge(a, b);
			DisConnect--;
		}
	//	std::cout << DisConnect << std::endl;
		if (DisConnect == 1)return true;
	}
//std::cout << DisConnect << std::endl;
	return (DisConnect == 1);
}

void SocialGraph::addEdge(int u, int v)
{
	if (u > MaxSize || u<0 || v>MaxSize || v < 0)
	{
		std::cout << "Out of range" << std::endl;
		return;
	}
	vertexNum = std::max({ vertexNum,u,v });
	edge[u][v] = edge[v][u] = 1;
}

void SocialGraph::deleteEdge(int u, int v)
{
	if (u > MaxSize || u<0 || v>MaxSize || v < 0)
	{
		std::cout << "Out of range" << std::endl;
		return;
	}
	edge[u][v] = edge[v][u] = INF;
}

void SocialGraph::addPeople(std::string name)
{

	vertexName[vertexNum] = name;
	int num,friend_;
	std::cout << name << " is numbered " << vertexNum++<<std::endl;
	RealNum++;
	std::cout << "Input the number of " << name << "'s friends:";
	std::cin >> num;
	std::cout << name << "'s friends are (id):";
	for (int j = 0; j < num; j++)
	{
		std::cin >> friend_;
		edge[vertexNum-1][friend_] = edge[friend_][vertexNum - 1] = 1;
	}
	std::cout << std::endl;
}
void SocialGraph::deletePeople(int u)
{
	if (u > MaxSize || u<0 )
	{
		std::cout << "Out of range" << std::endl;
		return;
	}
	RealNum--;
	for (int i = 0; i < vertexNum; i++)
		edge[u][i] = edge[i][u] = 0;
	std::cout << vertexName[u] << " has been deleted from the social graph" << std::endl;
}
void SocialGraph::getVDCC_EDCC()
{

	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(fa, -1, sizeof fa);
	memset(is_bridge, 0, sizeof is_bridge);
	times = 1;
	memset(is_cut, 0, sizeof is_cut);
	for (int i = 0; i < vertexNum; i++)
		if (!dfn[i])
		{
			DCC_DFS(i);
		}
	std::vector<int>crucialPeople;
	for (int i = 0; i < vertexNum; i++)
		if (is_cut[i])
		{
			crucialPeople.push_back(i);
		}
	if (crucialPeople.size())
	{
		for (auto i : crucialPeople)
			std::cout << i << " ";
		std::cout << "是这张社交网络图中的关键人物,去除其中任意一人这张图的不连通度都将增加" << std::endl;
	}
	else
		std::cout << "这张社交网络图中不存在关键人物" << std::endl;
	std::vector<std::pair<int, int>>crucialEdge;
	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < i; j++)
			if (is_bridge[i][j])
				crucialEdge.push_back({ i,j });
	if (crucialEdge.size())
	{
		for (auto [x, y] : crucialEdge)
		{
			std::cout << "(" << x << "," << y << ")";

		}
		std::cout << "是这张社交网络图中的关键关系，去除其中任意一个关系这张图的不连通度都将增加" << std::endl;
	}
	else
		std::cout << "这张社交网络图中不存在关键关系" << std::endl;
}
void SocialGraph::DCC_DFS(int x)
{
	dfn[x] = low[x] = ++times;
	int child = 0;
	for (int y = 0; y < vertexNum; y++)
	{
		if (edge[x][y] == 1)
		{
			if (!dfn[y])
			{
				child++;fa[y] = x;
				DCC_DFS(y);
				if (fa[x] == -1 && child >= 2)	is_cut[x] = 1;
				if (fa[x] != -1 && low[y] >= dfn[x]) is_cut[x] = 1;
				if (low[y] > dfn[x])	is_bridge[x][y] = is_bridge[y][x] = 1;
				low[x] = std::min(low[x], low[y]);
			}
			else if (fa[x] != y)
				low[x] = std::min(low[x], dfn[y]);
		}
	}
}