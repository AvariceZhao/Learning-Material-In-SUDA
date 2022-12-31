#include <iostream>
#include <cstring>
using namespace std;
template <typename Data>
class Queue
{

private:
	Data data_queue[100000] = {0};
	int front = 0;
	int rear = -1;
	int siz = 0;

public:
	void push(Data u)
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
};

int main()
{
	
}