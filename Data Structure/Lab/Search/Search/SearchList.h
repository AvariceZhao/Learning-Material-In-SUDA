#pragma once
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include"Timer.hpp"
struct Info
{
	long double time=0.0;
	unsigned long long compare=0;
};
class SearchList
{
public:
	SearchList(){};
	SearchList(int size, bool unordered);
	int sequenceSearch(int target,Info &info);
	int binarySearchRecursive(int target,Info &info);
	int binarySearchNonRecursive(int target, Info& info);

private:
	static const int NOT_FOUND;
	static const int MAX_SIZE = 10000010;
	 int datas[MAX_SIZE];
	int size;
	int binaryRecursive(int low, int high, int target, Info& info);
	
};