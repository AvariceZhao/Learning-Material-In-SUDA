
#include<iostream>
using namespace std;
class stack
{
	private:
			int stk[100000]={0};
			int Bottom=0;
			int Top=-1;
	public:
			void push(int u)
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
			int top()
			{
				return stk[Top];
			}
  
};
void detach(int n)
{
	stack stk;
	int temp=n;
	for(int i=2;i<=n;i++)
	{
		while(n%i==0)
		{
			stk.push(i);
			n/=i;
		}
	}
	cout<<temp<<"="<<stk.top();stk.pop();
	while(!stk.empty())
	{
		cout<<"*"<<stk.top();
		stk.pop();
	}
}
int main() {

int n;

cin >> n;

detach(n);

}