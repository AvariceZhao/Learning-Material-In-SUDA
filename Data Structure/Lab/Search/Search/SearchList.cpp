#include "SearchList.h"

const int SearchList::NOT_FOUND = -1;
SearchList::SearchList(int _size, bool unordered)
{
	size = _size;
	for (int i = 0; i < size; i++)
		datas[i] = 2 * i;
	if (unordered)
	{
		std::srand(std::time(0));
		for (int i = 0; i < size; i++)
		{
			int p = std::rand() % size;
			std::swap(datas[p], datas[i]);
		}
	}
}

int SearchList::sequenceSearch(int target, Info& info)
{
	Timer timer;
	for (int i = 0; i < size; ++i)
	{
		
		if (info.compare++, target == datas[i])
		{
			info.time = timer.runtime();
			
			return i;
		}
	}
	info.time = timer.runtime();
	return NOT_FOUND;
}
int SearchList::binarySearchRecursive(int target, Info& info)
{
	Timer timer;
	int res = binaryRecursive(0, size - 1, target, info);
	info.time = timer.runtime();
	return res;
}
int SearchList::binaryRecursive(int low, int high, int target, Info& info)
{
	if (high < low)return NOT_FOUND;
	int mid = low + high >> 1;

	if (info.compare++,target < datas[mid])
	{
		return binaryRecursive(low, mid - 1, target, info);
	}
	else if (info.compare++, target > datas[mid])
	{
		return binaryRecursive(mid + 1, high, target, info);
	}
	return mid;
}
int SearchList::binarySearchNonRecursive(int target, Info& info)
{
	Timer timer;
	int low = 0, high = size - 1, mid;
	while (low <= high)
	{
		mid = low + high >> 1;
		if (info.compare++, target < datas[mid])
			high = mid - 1;
		else if (info.compare++, target > datas[mid])
			low = mid + 1;
		else
		{
			info.time = timer.runtime();
			return mid;
		}
	}
	info.time = timer.runtime();
	return NOT_FOUND;
}