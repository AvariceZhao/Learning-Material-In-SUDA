#pragma once
#include"linkedListNode.h"
template<typename DataType>
class   linkedList
{
public:
	linkedList();
	linkedList(DataType a[], int len);
	~linkedList();
	linkedList(const linkedList<DataType>&);
	int Length();
	DataType Get(int i);
	int Find(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	int Empty();
	void Print();
	void Clear();
protected:
	Node<DataType>* head;
	int size;
};
template<typename DataType>
linkedList<DataType>::linkedList(const linkedList<DataType>& list) : head(new Node<DataType>{ DataType(), nullptr })
{
	
	Node<DataType>* thisList = head, * otherList = list.head->next;
	while (otherList != nullptr) {
		thisList->next = new Node<DataType>{ otherList->data, nullptr };
		thisList = thisList->next;
		otherList = otherList->next;
	}
}
template<typename DataType>
linkedList<DataType>::linkedList()
{
	head = new Node<DataType>;
	head->next = NULL;
	//size = 0;
}
template<typename DataType>
int linkedList<DataType>::Empty()
{
	return head->next == NULL;
}

template<typename DataType>
void linkedList<DataType>::Print()
{
	Node<DataType>* p = head->next;
	while (p != NULL)
	{
		if (p->next != NULL)
			std::cout << p->data << " ";
		else
			std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template<typename DataType>
int linkedList<DataType>::Length()
{
	Node<DataType>* p = head->next;
	int count = 0;
	while (p != NULL)
	{

		p = p->next;
		count++;
	}
	return count;
}

template<typename DataType>
DataType linkedList<DataType>::Get(int i)
{
	Node<DataType>* p = head->next;
	int count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	throw std::runtime_error{"Index Error"};
	else return p->data;
}

template<typename DataType>
int linkedList<DataType>::Find(DataType x)
{
	Node<DataType>* p = head->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x)return count;
		p = p->next;
		count++;
	}
	return 0;
}
template<typename DataType>
void linkedList<DataType>::Insert(int i, DataType x)
{
	Node<DataType>* p = head, * s = NULL;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL) return;
	s = new Node<DataType>;
	s->data = x;
	s->next = p->next;
	p->next = s;
}


template<typename DataType>
linkedList<DataType>::linkedList(DataType a[], int n)
{
	head = new Node<DataType>;
	Node<DataType>* r = head, * s = NULL;
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; s->data = a[i];
		r->next = s; r = s;
	}
	r->next = NULL;
}
template<typename DataType>
DataType linkedList<DataType>::Delete(int i)
{
	DataType x;
	Node<DataType>* p = head, * q = NULL;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)
		throw std::runtime_error{ "Delete Index Error" };
	else
	{
		q = p->next; x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}
template<typename DataType>
linkedList<DataType>::~linkedList()
{
	Node<DataType>* p = head;
	while (head != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
}
template<typename DataType>
void linkedList<DataType>::Clear()
{
	while (head->next != NULL)
		Delete(1);
}
