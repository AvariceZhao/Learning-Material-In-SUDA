#include"Tree.h"
Tree::Tree()
{
	memset(parent, -1, sizeof parent);
	memset(depth, -1, sizeof depth);
	num = 0;
	vertexNum.clear();
}
Tree::~Tree(){}

void Tree::SaveInfo(int i)
{
	std::string s1;
	getline(std::cin, s1);
	int temp = s1.find_last_of(' ') - s1.find_first_of(' ') + 1;//计算空格数
	if (i)
		s1.erase(0, temp);//删除空格
	vertexNum[s1] = num++;//给名字编号
	depth[num - 1] = temp;//记录层数=空格数
	if (i == 0)
		depth[num - 1] = 0;
	int pos = num - 2;
	while (depth[num - 1] <= depth[pos] && pos >= 0)
		pos--;
	parent[num - 1] = pos;
}
bool Tree::judge(std::string s1, std::string s2, std::string s3)
{
	int num1 = vertexNum[s1], num2 = vertexNum[s2];
	if (s3 == "child")
		return parent[num1] == num2 ? true : false;
	else if (s3 == "parent")
		return parent[num2] == num1 ? true : false;
	else if (s3 == "sibling")
		return parent[num1] == parent[num2] ? true : false;
	else if (s3 == "descendant")
	{
		while (num1 >= 0)
		{
			num1 = parent[num1];
			if (num1 == num2)break;
		}
		if (num1 >= 0)return true;
		return false;
	}
	else
	{
		while (num2 >= 0)
		{
			num2 = parent[num2];
			if (num1 == num2)break;
		}
		if (num2 >= 0)return true;
		return false;
	}
}