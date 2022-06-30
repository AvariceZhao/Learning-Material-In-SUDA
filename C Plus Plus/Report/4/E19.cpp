#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,x;
	vector<int>nums;
	cin>>n;
	while(n--)
	{
		cin>>x;
		nums.push_back(x);
	}
	reverse(nums.begin(),nums.end());
	for(auto num:nums)
	cout<<num<<" ";
	return 0;
}
