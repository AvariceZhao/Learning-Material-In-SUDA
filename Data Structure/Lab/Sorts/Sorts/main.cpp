#include "SortList.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int base = 50;
	string s[3] = { "order","reverse","random" };
	string path = "D://data_";
	
	for (int i = 1; i <= 5; i++)
	{
	
		cout <<"----------------------------" << "Length:"  << base << "-----------------------------------" << endl;
		for (int j = 0; j < 3; j++)
		{
			string temp = s[j];
			cout <<"-----" << temp <<"-----" << endl;
			string file_path = path + temp + "_" + to_string(base) + ".txt";
			Info info;

			SortList bubbleSortList(file_path);
			cout << "bubbleSort" << endl;
			info = bubbleSortList.bubbleSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms"<<endl;

			SortList quickSortList(file_path);
			cout << "quickSort" << endl;
			info = quickSortList.quickSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms" << endl;

			SortList insertSortList(file_path);
			cout << "insertSort" << endl;
			info = insertSortList.insertSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms" << endl;


			SortList selectSortList(file_path);
			cout << "selectSort" << endl;
			info = selectSortList.selectSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms" << endl;


			SortList mergeSortList(file_path);
			cout << "mergeSort" << endl;
			info = mergeSortList.mergeSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms" << endl;


			SortList shellSortList(file_path);
			cout << "shellSort" << endl;
			info = shellSortList.shellSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms" << endl;

			SortList heapSortList(file_path);
			cout << "heapSort" << endl;
			info = heapSortList.heapSort();
			cout << "移动次数:" << info.move << endl << "比较次数" << info.compare << endl << "运行时间：" << info.time << "ms" << endl;

		}
		cout << "---------------------------------------------------------" << endl;
		
		base *= 10;
	}
	
	
	return 0;
}


