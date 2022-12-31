#include "Node.h"
template<typename data_type>
class Stack
{
    public:
    Stack();
    ~Stack();
    bool empty()const;
    void push(const data_type &item);
    void pop();
    data_type top();

    private:
    Node<data_type> * top_node;
};
template<typename data_type>
Stack<data_type>::Stack()
{
    top_node=NULL;
}
template<typename data_type>
void Stack<data_type>:: push(const data_type &item)
{
    Node<data_type> *s=NULL;
    s=new Node<data_type>;
    s->data=item;
    s->next=top_node;
    top_node=s;

}
template<typename data_type>
bool Stack<data_type>:: empty()const
{
    return top_node==NULL;
}
template<typename data_type>
Stack<data_type>::~Stack()
{
    while(!empty())
        pop();
}
template<typename data_type>
void Stack<data_type>::pop()
{
  Node<data_type>*p=top_node;
  top_node=top_node->next;
  delete p;
}
template<typename data_type>
data_type Stack<data_type>::top()
{
    data_type x=top_node->data;
    return x;
}
