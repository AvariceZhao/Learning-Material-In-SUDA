//fw
#include<iostream>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=1e5+10;

template<typename T>
class stack
{
	private:
			T stk[100000]={0};
			int Bottom=0;
			int Top=-1;
	public:
			void push(T u)
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
			T top()
			{
				return stk[Top];
			}
  
};
int main()
{
 	stack<int>q;
 	q.push(1);
 	cout<<q.top();
    return 0;
}