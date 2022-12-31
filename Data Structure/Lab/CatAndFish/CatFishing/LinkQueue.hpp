#include "Node.h"

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

    private:
    Node<data_type> *Front,*Rear;

};
template<typename data_type>
Queue<data_type>::Queue()
{
    Node<data_type>* s=NULL;
    s=new Node<data_type>;
    s->next=NULL;
    Front=Rear=s;
}
template<typename data_type>
Queue<data_type>::~Queue()
{
    while(!empty())
        pop();
}
template<typename data_type>
bool Queue<data_type>::empty()
{
    return Front==Rear;
}
template<typename data_type>
void Queue<data_type>::push(data_type  item)
{
    Node<data_type> * s=NULL;
    s=new Node<data_type>;
    s->data=item;
    s->next=NULL;
    Rear->next=s;
    Rear=s;
}
template<typename data_type>
void Queue<data_type>::pop()
{
Node<data_type> *p = NULL;
p = Front->next; 
Front->next = p->next; 
if (p->next == NULL) Rear = Front; 
delete p;
}
template<typename data_type>
data_type Queue<data_type>::front()
{
    data_type x=Front->next->data;
    
    return x;
}
