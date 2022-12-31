#include<iostream>
#pragma once
template<typename data_type>
struct LinkNode
{
    data_type data;
    LinkNode<data_type>* next;
};
template<typename data_type>
class Queue
{
public:
    Queue();
    ~Queue();
    bool empty();
    data_type front();
    void push(data_type item);
    void pop();
    int size();
private:
    LinkNode<data_type>* Front, * Rear;
    int _size=0;
};
template<typename data_type>
int Queue<data_type>::size()
{
    return _size;
}
template<typename data_type>
Queue<data_type>::Queue()
{
    LinkNode<data_type>* s=NULL;
    s=new LinkNode<data_type>;
    s->next=NULL;
    Front=Rear=s;
}
template<typename data_type>
Queue<data_type>::~Queue()
{
    while(!empty())
        pop();
    _size = 0;
}
template<typename data_type>
bool Queue<data_type>::empty()
{
    return Front==Rear;
}
template<typename data_type>
void Queue<data_type>::push(data_type  item)
{
    LinkNode<data_type> * s=NULL;
    s=new LinkNode<data_type>;
    s->data=item;
    s->next=NULL;
    Rear->next=s;
    Rear=s;
    _size++;
}
template<typename data_type>
void Queue<data_type>::pop()
{
LinkNode<data_type> *p = NULL;
p = Front->next; 
Front->next = p->next; 
if (p->next == NULL) Rear = Front; 
delete p;
_size--;
}
template<typename data_type>
data_type Queue<data_type>::front()
{
    data_type x=Front->next->data;
    
    return x;
}
