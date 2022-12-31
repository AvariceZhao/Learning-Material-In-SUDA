
#include <iostream>
#include<iomanip>
#include"SearchList.h"
using namespace std;
int main()
{

	int n, m;
	cout << "输入表的长度" << endl;
	cin >> n;
	cout << "输入查询次数" << endl;
	cin >> m;
	SearchList orderedList(n, 0), unorderedList(n, 1);
	
	
	
	
	Info sequenceOrderedSuccess;
	//有序表的顺序查找 成功的情况下
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m;
		Info info{};
		orderedList.sequenceSearch(num, info);
	//	cout << info.time << endl;
		sequenceOrderedSuccess.compare += info.compare;
		sequenceOrderedSuccess.time += info.time;
	}
	sequenceOrderedSuccess.compare /= m;
	sequenceOrderedSuccess.time /= m;
	cout << "有序表成功顺序查找情况下：" << endl << "平均查找时间："<<fixed<<setprecision(6) << sequenceOrderedSuccess.time <<"s" << endl << "平均比较次数：" << sequenceOrderedSuccess.compare << endl;

	//有序表的顺序查找失败的情况下
	Info sequenceOrderedFail;
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m+1;
		Info info{};
		unorderedList.sequenceSearch(num, info);
		sequenceOrderedFail.compare += info.compare;
		sequenceOrderedFail.time += info.time;
	}
	sequenceOrderedFail.compare /= m;
	sequenceOrderedFail.time /= m;
	cout << "有序表失败顺序查找的情况下" << endl << "平均查找时间：" << fixed << setprecision(6)  << sequenceOrderedFail.time<<"s" << endl << "平均比较次数：" << sequenceOrderedFail.compare << endl;

	//无序表成功查找的情况下
	Info sequenceUnorderedSuccess;
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m;
		Info info{};
		unorderedList.sequenceSearch(num, info);
		//	cout << info.time << endl;
		sequenceUnorderedSuccess.compare += info.compare;
		sequenceUnorderedSuccess.time += info.time;
	}
	sequenceUnorderedSuccess.compare /= m;
	sequenceUnorderedSuccess.time /= m;
	cout << "无序表成功顺序查找情况下：" << endl << "平均查找时间：" << fixed << setprecision(6) << sequenceUnorderedSuccess.time << "s" << endl << "平均比较次数：" << sequenceUnorderedSuccess.compare << endl;
	//无序表失败查找的情况下
	Info sequenceUnorderedFail;

	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m + 1;
		Info info{};
		unorderedList.sequenceSearch(num, info);
		sequenceUnorderedFail.compare += info.compare;
		sequenceUnorderedFail.time += info.time;
	}
	sequenceUnorderedFail.compare /= m;
	sequenceUnorderedFail.time /= m;
	cout << "无序表失败顺序查找的情况下" << endl << "平均查找时间：" << fixed << setprecision(6) << sequenceUnorderedFail.time << "s" << endl << "平均比较次数：" << sequenceUnorderedFail.compare << endl;


	
//	cout << "init" << clock() << endl;
	//有序表二分查找成功的情况下
	Info binaryOrderedSuccess;
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m;
		Info info{};
		orderedList.binarySearchRecursive(num, info);
		//cout << info.time << endl;
		binaryOrderedSuccess.compare += info.compare;
		binaryOrderedSuccess.time += info.time;
	}
	binaryOrderedSuccess.compare /= m;
	binaryOrderedSuccess.time /= m;
	cout << "有序表成功递归二分查找情况下：" << endl << "平均查找时间：" << fixed << setprecision(10) << binaryOrderedSuccess.time << "s" << endl << "平均比较次数：" << binaryOrderedSuccess.compare << endl;
	
	
	//有序表二分查找失败
	Info binaryOrderedFail;
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m+1;
		Info info{};
		orderedList.binarySearchRecursive(num, info);
		//	cout << info.time << endl;
		binaryOrderedFail.compare += info.compare;
		binaryOrderedFail.time += info.time;
	}
	binaryOrderedFail.compare /= m;
	binaryOrderedFail.time /= m;
	cout << "有序表的失败递归二分查找情况下：" << endl << "平均查找时间：" << fixed << setprecision(10) << binaryOrderedFail.time << "s" << endl << "平均比较次数：" << binaryOrderedFail.compare << endl;
	
	//有序表非递归二分查找成功的情况下
	Info nonRecursiveBinaryOrderedSuccess;
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m;
		Info info{};
		orderedList.binarySearchNonRecursive(num, info);
		//cout << info.time << endl;
		nonRecursiveBinaryOrderedSuccess.compare += info.compare;
		nonRecursiveBinaryOrderedSuccess.time += info.time;
	}
	nonRecursiveBinaryOrderedSuccess.compare /= m;
	nonRecursiveBinaryOrderedSuccess.time /= m;
	cout << "有序表成功非递归二分查找情况下：" << endl << "平均查找时间：" << fixed << setprecision(10) << nonRecursiveBinaryOrderedSuccess.time << "s" << endl << "平均比较次数：" << nonRecursiveBinaryOrderedSuccess.compare << endl;
	
	
	//有序表非递归二分查找失败的情况下
	Info nonRecursiveBinaryOrderedFail;
	for (int i = 0; i < m; i++)
	{
		int num = 2 * i * n / m+1;
		Info info{};
		orderedList.binarySearchNonRecursive(num, info);
		//cout << info.time << endl;
		nonRecursiveBinaryOrderedFail.compare += info.compare;
		nonRecursiveBinaryOrderedFail.time += info.time;
	}
	nonRecursiveBinaryOrderedFail.compare /= m;
	nonRecursiveBinaryOrderedFail.time /= m;
	cout << "有序表失败非递归二分查找情况下：" << endl << "平均查找时间：" << fixed << setprecision(10) << nonRecursiveBinaryOrderedSuccess.time << "s" << endl << "平均比较次数：" << nonRecursiveBinaryOrderedSuccess.compare << endl;
	
	//cout << "end" << clock() << endl;
	return 0;

}

