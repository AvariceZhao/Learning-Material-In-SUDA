#pragma once
#include"linkedListNode.h"
template<typename DataType>
class circularLinkedList
{
public:
	circularLinkedList();
	~circularLinkedList();
	circularLinkedList(DataType a[], int n);
	bool Empty();
	int Length();
	void Print();
	DataType Get(int i);
	void Insert(int index, DataType elem);
	int Find(DataType x);
	DataType Delete(int i);
	void Clear();
private:
	Node<DataType>* head;
};
template<typename DataType>
circularLinkedList<DataType>::circularLinkedList()
{
	head = new Node<DataType>;
	head->data = NULL;
	head->next = head;
}
template<typename DataType>
circularLinkedList<DataType>::~circularLinkedList()
{
	Node<DataType>* p;
	while (head->next != head)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}
}
template<typename DataType>
circularLinkedList<DataType>::circularLinkedList(DataType a[], int n)
{
	head = new Node<DataType>;
	Node<DataType>* p = head;
	for (int i = 0; i < n; i++)
	{
		Node<DataType>* s = new Node<DataType>;
	
		s->data=a[i];
		s->next = head;
		p->next = s;
		p = s;
	}
	//std::cout << "创建成功！" << std::endl;


}
template<typename DataType>
bool circularLinkedList<DataType>::Empty()
{
	return head->next == head;
}
template<typename DataType>
int circularLinkedList<DataType>::Length()
{
	Node<DataType>* p = head;
	int cnt = 0;
	while (p->next != head)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}
template<typename DataType>
void circularLinkedList<DataType>::Print()
{
	Node<DataType>* p = head;
	while (p->next != head)
	{
		p = p->next;
		std::cout << p->data << " ";

	}
	std::cout << std::endl;
}
template<typename DataType>
DataType circularLinkedList<DataType>::Get(int index)
{
	Node<DataType>* p = head->next;
	int j = 1;
	while (p != head && j < index)
	{
		p = p->next;
		j++;
	}
	if (p == head || j > index)
		throw std::runtime_error{ "index error" };
	
	return p->data;

}
template<typename DataType>
void circularLinkedList<DataType>::Insert(int index, DataType elem)
{
	Node<DataType>* p = head;
	Node<DataType>* s = new Node<DataType>;
	int j = 1;
	while (p->next != head && j < index)
	{
		p = p->next;
		j++;
	}
	if(p->next==head||j>index)
		throw std::runtime_error{ "index error" };
	s->data = elem;
	s->next = p->next;
	p->next = s;
}

template<typename DataType>
DataType circularLinkedList<DataType>::Delete(int index)
{
	Node<DataType>* p = head;
	Node<DataType>* s = new Node<DataType>;
	int j = 1;
	while (p->next != head && j < index)
	{
		p = p->next;
		j++;
	}
	if (p->next == head || j > index)
		throw std::runtime_error{ "index error" };
	s = p->next;
	DataType delete_data = s->data;
	p->next = s->next;
	
	delete s;
	return delete_data;
}
template<typename DataType>
int circularLinkedList<DataType>::Find(DataType x)
{
	Node<DataType>* p = head->next;
	int count = 1;
	while (p != head)
	{
		if (p->data == x)return count;
		p = p->next;
		count++;
	}
	return 0;
}
template<typename DataType>
void circularLinkedList<DataType>::Clear()
{
	while (head->next != head)
		Delete(1);
}
