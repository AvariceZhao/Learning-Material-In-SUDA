
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
class stack
{
	private:
			char stk[10000]={0};
			int Bottom=0;
			int Top=-1;
	public:
			void push(char u)
			{
				stk[++Top]=u;
			}
			void pop()
			{
				Top--;
			}
			bool empty()
			{
				return Top<Bottom;
			}
			char top()
			{
				return stk[Top];
			}
  
};
string stringdeal(string s)
{
	stack stk;
	int num=0;
	for(auto c:s)
	{
		if(stk.empty()||c!=stk.top())
		{
			stk.push(c);
			num++;
		}
		else if (c==stk.top())
		{
			stk.pop();	num--;
		}
	}
	string ans;int index=0;
	for(int i=0;i<num;i++)ans+=' ';
	while(!stk.empty())
	{
		ans[index++]=stk.top();
		stk.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main() {

	string s; 

	cin >> s;

	cout << stringdeal(s);

}