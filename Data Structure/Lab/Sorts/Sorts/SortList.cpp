#include"SortList.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<cstring>
#include<vector>
SortList::SortList(int size)//测试用构造函数
{
	//test
	std::cin >> size;
	length = size;
	datas = new int[length] {};
	for (int i = 0; i < length; i++)
		std::cin >> datas[i];

}
SortList::SortList(std::string path)//从文件初始化顺序表
{
	std::ifstream iFile(path);
	if (iFile.fail())
	{
		std::cout << "Path error" << std::endl;
		return;
	}
	int _size = 0;
	iFile >> _size;
	length = _size;
	datas = new int[length] {};
	for (int i = 0; i < _size; i++)
		iFile >> datas[i];

	iFile.close();

}
SortList::~SortList()
{
	delete[]datas;//析构

}
void SortList::print()
{
	for (int i = 0; i < length; i++)
		std::cout << datas[i] << " ";
	std::cout << std::endl;
}
Info SortList::bubbleSort()
{
	Info info{}; Timer timer;
	for(int i=0;i<length;i++)
		for (int j = 0; j < i; j++)
		{
			if (info.compare++, datas[j] > datas[i])
			{
				std::swap(datas[j], datas[i]);
				info.move++;
			}
		}
	info.time = timer.runtime();
	return info;

}
Info SortList::quickSort()//快排主函数
{
	Info info;
	Timer timer;
	quickSortRecursion(0, length - 1, info);
	info.time = timer.runtime();
	return info;
}
int SortList::Partition(int left, int right, Info& info)//快排划分函数
{
	int i = left, j = right;
	while (i < j)
	{
		while (i < j && (info.compare++ && datas[i] <= datas[j]))j--;
		if (i < j) { std::swap(datas[i], datas[j]); info.move++; i++; }
		while (i < j && (info.compare++ && datas[i] <= datas[j]))i++;
		if (i < j) { std::swap(datas[i], datas[j]); info.move++; j--; }
	}
	return i;
}
void SortList::quickSortRecursion(int left,int right,Info &info)//快排递归函数
{
	if (left >= right)return;
	int p = Partition(left, right, info);
	quickSortRecursion(left, p - 1, info);
	quickSortRecursion(p + 1, right, info);

}
Info SortList::insertSort()//插入排序
{
	Info info{};
	Timer timer;
	int i, j;
	for (i = 1; i < length; i++)
	{
		int temp = datas[i];
		for ( j = i - 1; j >= 0 && (info.compare++, temp < datas[j]); j--)
		{
			datas[j + 1] = datas[j];
			info.move++;
		}
		datas[j + 1] = temp;
	}
	info.time = timer.runtime();
	return info;

}

Info SortList::selectSort()//选择排序
{
	Info info{};
	Timer timer;
	for (int i = 0; i < length; i++)
	{
		int index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (info.compare++, datas[j] < datas[index])index = j;

		}
		if (index != i)std::swap(datas[i], datas[index]), info.move++;

	}
	info.time = timer.runtime();
	return info;
}

Info SortList::mergeSort()//归并排序主函数
{
	Info info{};
	Timer timer;
	mergetsortRecursion(0, length - 1, info);
	info.time = timer.runtime();
	return info;
}
void SortList::mergetsortRecursion(int left, int right,Info& info)//归并排序递归函数
{
	if (left >= right)return;
	int mid = (left + right) / 2;
	mergetsortRecursion(left, mid,info);
	mergetsortRecursion(mid+1, right, info);
	merge(left, mid, right, info);
}
void SortList::merge(int left1, int right1, int right2, Info& info)//归并排序合并函数
{
	auto* temp = new int[length];
	int i = left1, j = right1 + 1, k = left1;
	while (i <=right1 && j <= right2)
	{
		if (info.compare++, datas[i] <= datas[j])
		{
			temp[k++] = datas[i++];
		}
		else
		{
			temp[k++] = datas[j++];
		}
		info.move++;
	}
	while (i <= right1) 
	{ 
		temp[k++] = datas[i++];
		info.move++;
	}
	while (j <= right2) 
	{
		temp[k++] = datas[j++];
		info.move++;
	}
	for (i = left1; i <= right2; i++) 
	{
		datas[i] = temp[i];
	}
	delete[]temp;
}
Info SortList::shellSort()//希尔排序
{
	Info info{};
	Timer timer;
	int len, i, j, temp;
	for (len= length / 2; len >= 1; len /= 2)
	{
		for (i = len; i < length; i++)
		{
			int temp = datas[i];
			for (j = i - len; j >= 0 && (info.compare++, temp < datas[j]); j -= len)
			{
				datas[j + len] = datas[j];
				info.move++;
			}
			datas[j + len] = temp;
		}
	}
	info.time = timer.runtime();
	return info;

}
Info SortList:: heapSort()//堆排序主函数
{
	Info info{};
	Timer timer;
	for (int i = std::ceil(length / 2) - 1; i >= 0; i--)
		heapShift(i, length - 1,info);
	for (int i = 1; i < length; i++)
	{
		std::swap(datas[0], datas[length - i]), info.move++;
		heapShift(0, length - i - 1, info);
	}
	info.time = timer.runtime();
	return info;

}
void SortList::heapShift(int k, int last, Info& info)//堆排序调整堆函数
{
	int i = k, j = 2 * i + 1;
	while (j <= last)
	{
		if (j < last && (info.compare++, datas[j] < datas[j + 1]))j++;
		if (info.compare++, datas[i] > datas[j])break;
		else
		{
			std::swap(datas[i], datas[j]);
			info.move++;
			i = j; j = 2 * i + 1;
		}
	}
}
