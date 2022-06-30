#include<iostream>
using namespace std;
int main()
{	
	int n,sum=0,nums=1,days;
	cout<<"请输入天数"<<endl;
	cin>>n;
	while(days<n)
	{
		for(int i=1;i<=nums;i++)
		{
			sum+=nums;
			days+=1;
			if(days==n)
			break;
		}
		nums++;
	}
	cout<<"共获得"<<sum<<"支粉笔"<<endl;
	return 0;
}
