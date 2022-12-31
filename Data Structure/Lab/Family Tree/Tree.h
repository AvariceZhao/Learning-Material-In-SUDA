#pragma once
#include<map>
#include<cstring>
#include<string>
#include<istream>
#include<iostream>
class Tree
{
public:
	Tree();
	~Tree();
	void SaveInfo(int i);
	bool judge(std::string s1, std::string s2, std::string s3);
private:
	static const int MaxSize = 1000 + 10;
	int depth[MaxSize], parent[MaxSize];
	std::map<std::string, int>vertexNum;
	int num = 0;

};