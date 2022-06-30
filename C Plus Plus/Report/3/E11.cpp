#include<iostream>
using namespace std;
bool IsPrime(int num)
{
	for(int i=2;i<=num/i;i++)
		if(num%i==0)
			return false;
	return true;
}
int main()
{
	//ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	int cnt=0; 
	for(int i=2;i<=1000;i++)
	{
		if(IsPrime(i))
		{
			cout<<i<<" ";
			cnt++;
			if(cnt%8==0)
				cout<<endl;
		}
	}	
	return 0;
}
