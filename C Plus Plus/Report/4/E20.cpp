#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>words={"january","february","mar","april","may","june","july","august","september","october","november","december"};
void quicksort(int left,int right)
{	
	if(left>right)return;
	int i,j;string t,t1;
	t=words[left];i=left;j=right;
	while(i!=j)
	{
	while(words[j]>=t&&i<j)j--;
	while(words[i]<=t&&i<j)i++;
	if(i<j)swap(words[i],words[j]);
	}
	words[left]=words[i];
	words[i]=t;
	quicksort(left,i-1);
	quicksort(i+1,right);
}

int main()
{
	quicksort(0,11);
	for(auto l:words)
	cout<<l<<endl;
	return 0;
}
