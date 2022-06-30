#include<iostream>
#include<iomanip>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
	int nums[10];
 	int maxx=-INF,minn=INF;
 	double sum=0;
 	for(int i=0;i<=9;i++)
 	{
 		cin>>nums[i];
 		maxx=max(maxx,nums[i]);
 		minn=min(minn,nums[i]);
 		sum+=nums[i];
 	}
 	cout<<maxx<<" "<<minn<<" "<<fixed<<setprecision(3)<<sum/10<<endl;
	
    return 0;
}
