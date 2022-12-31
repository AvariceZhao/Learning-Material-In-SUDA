#pragma once
template<typename data_type>
struct Node
{
    data_type data;
    Node<data_type>* next;
};
template<typename data_type>
class Stack
{
    public:
    Stack();
    ~Stack();
    void clear();
    bool empty()const;
    void push(const data_type &item);
    data_type pop();
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
data_type  Stack<data_type>::pop()
{

   auto x = top();
  Node<data_type>*p=top_node;
  if (empty())
      throw underflow_error{ "" };
  top_node=top_node->next;
  delete p;
  return x;
}
template<typename data_type>
data_type Stack<data_type>::top()
{
    if(empty())
        throw underflow_error{""};
    data_type x=top_node->data;
    return x;
}
template<typename data_type>
void Stack<data_type>::clear()
{
    while (!empty())
        pop();
}