#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;
int ReadInfo(const char filePath[],vector< vector<int> > &vecInt2D)//定义函数
{
    ifstream iFile;
    iFile.open(filePath);//打开文件
    if(iFile.fail())//错误则返回-1
    return -1;

	int lines=0;//计算行数
	char buff[256];
	while(iFile.getline(buff,256))//按行读入
	{	
		stringstream is(buff);//#include<sstream>
		vector<int>tmp;//定义临时向量
		int temp;
		while(is>>temp)//依次读入每个数字
		tmp.push_back(temp);
		vecInt2D.push_back(tmp);//将临时向量push_back
		lines++;
	}
	
	iFile.close();//关闭文件
    return lines;
   
}
void ShowData(vector< vector<int> > &vecInt2D)
{
	for(int i=0;i<vecInt2D.size();i++)//遍历每行
	{
		for(int j=0;j<vecInt2D[i].size();j++)//遍历一行中的每个数字
			cout<<setw(5)<<right<<vecInt2D[i][j];//输出
		cout<<endl;//换行
	}
}	
vector<int> GetNumbers(vector< vector<int> > &vecInt2D,bool flag=true)//定义函数以及缺省参数
{	
	vector<int>ans;
	if(flag)//求最大值
	{
	
	for(int i=0;i<vecInt2D.size();i++)
	{
		int num=-0x3f3f3f3f;//求最大值
		for(int j=0;j<vecInt2D[i].size();j++)
		{
			num=max(num,vecInt2D[i][j]); 
		}
		ans.push_back(num);//存储最大值
	}
	}
	else//求最小值
	{
		for(int i=0;i<vecInt2D.size();i++)
	{
		int num=0x3f3f3f3f;//求最小值
		for(int j=0;j<vecInt2D[i].size();j++)
		{
			num=min(num,vecInt2D[i][j]); 
		}
		ans.push_back(num);//存储最小值
	}
	}
	return ans;
}
void ShowData(vector<int>&vecB,int X=5,int Y=5)//定义函数以及缺省参数
{
	int count=0;
	for(int i=0;i<vecB.size();i++)
	{
		cout<<setw(Y)<<left<<vecB[i];//宽度为Y
		count++;
		if(count%X==0)//每行显示X个数
		cout<<endl;
	}


}
int DelVecNumber(vector<int>&vecB)
{
	int delCount=0;
	vector<int>::iterator p=vecB.begin();//定义迭代器
	while(p!=vecB.end())
	{
		if(count(vecB.begin(),vecB.end(),*p)>1)//如果有重复
		{
		p=vecB.erase(p);//删除
		delCount++;//计数
		}else
		p++;	
	}
	return delCount;
}
bool cmp(int num1,int num2)
{
	int t1=0,t2=0;
	while(num1!=0)//计算整数的各位数之和
	{
		t1+=num1%10;
		num1/=10;
	}
	while(num2!=0)//计算整数的各位数之和
	{
		t2+=num2%10;
		num2/=10;
	}
	return t1<t2;//按各位数之和升序排列
}
void SortData(vector<int>&vecB)
{
	sort(vecB.begin(),vecB.end(),cmp);//排序
}
int writeInfo(const char filePath[],vector<int>&vecB)
{
	ofstream oFile;
	oFile.open(filePath);//打开文件
	if(oFile.fail())//如果失败返回-1
		return -1;
	int count =0;//计算已经输出了多少个
	for(int i=0;i<vecB.size();i++)
	{
		oFile<<setw(5)<<right<<vecB[i];//宽度5右对齐
		count++;//计数
		if(count%4==0)//每四个换行
		oFile<<endl;
	}
	oFile.close();//关闭文件
    return 0;
}
int main()
{
	vector< vector<int> > vecInt2D;
	vector<int> vecB;
	int count;

	if (ReadInfo("d:\\data.txt", vecInt2D) == -1)
	{
		cout << "打开d:\\data.txt文件失败" << endl;
	}
	else
	{
		cout << "读取到" << vecInt2D.size() << "行整数" << endl;
	}
	cout << "读取到的二维向量为:\n";
	ShowData(vecInt2D);
	vecB = GetNumbers(vecInt2D);
	cout << "\n每行最大值构成的向量：\n";
	ShowData(vecB, 5);

	count = DelVecNumber(vecB);
	cout << "\n删除的重复元素个数为:" << count << endl;
	SortData(vecB);
	cout << "\n排序后的整数：\n";
	ShowData(vecB);

	if (writeInfo("d:\\result.txt", vecB) == -1)
	{
		cout << "打开d:\\result.txt文件失败!\n";
	}	
	return 0;
}
