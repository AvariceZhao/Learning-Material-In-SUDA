#include<iostream>
using namespace std;
int main()
{	double n,k,m,price=200; 	int cnt=1;
	cout<<"请输入n和k"<<endl;
	cin>>n>>k;
	m=n;
	while(m<price)
	{	
		m+=n;
		cnt++;
		price*=(1+k/100);
		if(cnt>20)
		{
		cout<<"Impossible";
		return 0;
		}
	}
cout<<cnt;
return 0;
}
