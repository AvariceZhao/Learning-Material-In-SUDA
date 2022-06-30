#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{	int cnts[100],nums,n;
	float ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cnts[i];
		ans+=ceil(cnts[i]*1.0/70)*0.1;
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
