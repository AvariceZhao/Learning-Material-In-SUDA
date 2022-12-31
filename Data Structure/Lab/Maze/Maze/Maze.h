#pragma once
class Maze
{
private:
	static const int max_size = 105;
	int map[max_size][max_size];
	int dist[max_size][max_size];
	int st[max_size][max_size];
	int in_path[max_size][max_size];
	int Row, Col;
	int pathNum = 0;
	int dx[8] = { 1,-1,0,0 ,1,1,-1,-1 };
	int dy[8] = { 0,0,1,-1 ,1,-1,1,-1 };
	void dfs(int x,int y,int tx,int ty);
public:
	Maze(int Rows, int Cols);
	void find_path(int sx, int sy,int tx,int ty);
	void init(int Rows, int Cols);
	int count_path(int sx,int sy,int tx,int ty);

};