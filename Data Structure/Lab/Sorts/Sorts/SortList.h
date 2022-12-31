#pragma once
#include<cstring>
#include"timer.hpp"
#include<iostream>
class Info {
public:
	unsigned long long compare=0;
	unsigned long long move=0;
	long double time=0;
};
class SortList
{
public:
	SortList(int size);
	SortList(std::string path);
	~SortList();
	void print();
	Info bubbleSort();
	Info quickSort();
	Info insertSort();
	Info selectSort();
	Info mergeSort();
	Info shellSort();
	Info heapSort();
	
	private:
	int* datas;
	int length;
	std::string type;
	int Partition(int left, int right, Info& info);
	void quickSortRecursion(int left, int right, Info& info);
	void mergetsortRecursion(int left, int right, Info& info);
	void  merge(int first, int right1, int right2, Info& info);
	void heapShift(int k, int last, Info& info);
	


};