#pragma once
#define MAXN 105
namespace UnionSet {

	int fa[MAXN], rank[MAXN];
	inline void init(int n)
	{
		for (int i = 0; i <= n; ++i)
		{
			fa[i] = i;
			rank[i] = 1;
		}
	}
	int find(int x)
	{
		return x == fa[x] ? x : (fa[x] = find(fa[x]));
	}
	inline void merge(int i, int j)
	{
		int x = find(i), y = find(j);
		if (rank[x] <= rank[y])
			fa[x] = y;
		else
			fa[y] = x;
		if (rank[x] == rank[y] && x != y)
			rank[y]++;
	}
	inline bool same(int i, int j) {
		return find(i) == find(j);
	}
}
