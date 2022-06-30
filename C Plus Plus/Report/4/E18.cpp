#include<iostream>
#include<iomanip>
using namespace std;
int arry [10]={13,24,35,46,57, 79, 93};
int main()
{

	int n,i;
	cin>>n;
	for( i=7;;i--)
	{
		if(arry[i-1]>=n)
		arry[i]=arry[i-1];
		else
		break;
	}
	arry[i]=n;
	for(int i=0;i<=7;i++)
	cout<<setiosflags(ios::right)<<setfill(' ')<<setw(4)<<arry[i]<<" ";
	cout<<endl;
	return 0;
}
