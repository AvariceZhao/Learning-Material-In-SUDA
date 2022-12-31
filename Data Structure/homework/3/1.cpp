#include<iostream>
using namespace std;
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
template<typename Data>
class  CirQueue
{
	private:
	Data data_queue[1000];
	int front = 0;
	int rear = -1;
	int siz = 0;

public:
	void EnQueue(Data u)
	{
		data_queue[++rear] = u;
		siz++;
	}
	void pop()
	{
		data_queue[front++];
		siz--;
	}
	bool empty()
	{
		return siz == 0;
	}
	Data get_front()
	{
		return data_queue[front];
	}
	int get_size()
	{
		return siz;
	}
	void PrintOut()
	{
		for(int i=front;i<=rear;i++)
		cout<<data_queue[i]<<" ";
	}
};
void reverseOdd(CirQueue<int> &sq)
{
	bool state[1000];
	stack<int>odd;
	CirQueue<int>even;
	int count=1;
	while(sq.get_size())
	{
		auto num=sq.get_front();
		sq.pop();
		state[count]=num%2;
		if(state[count]==1)
		{
			odd.push(num);
		}
		else
		{
			even.EnQueue(num);
		}
		count++;
	}
	for(int i=1;i<=count-1;i++)
	{
	if(state[i]==0)
    	{
    		sq.EnQueue(even.get_front());
    		even.pop();
    	}
    	else
    	{
    		sq.EnQueue(odd.top());
    		odd.pop();
    	}
	}	
}
int main() {

    int n,item;

    CirQueue<int> sq;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> item;

        sq.EnQueue(item);

    }

   reverseOdd(sq);

  sq.PrintOut();

}