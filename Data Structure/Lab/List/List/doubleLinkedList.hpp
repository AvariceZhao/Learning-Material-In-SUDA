#pragma once
#include"doubleLinkedListNode.h"
template<typename DataType>
class   doubleLinkedList
{
public:
	doubleLinkedList();
	doubleLinkedList(DataType a[], int len);
	~doubleLinkedList();
	int Length();
	DataType Get(int i);
	int Find(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	int Empty();
	void Print();
	void Clear();
private:
	doubleNode<DataType>* head;
};
template<typename DataType>
doubleLinkedList<DataType>::doubleLinkedList()
{
	head = new doubleNode<DataType>;
	head->next = NULL;
	head->prior = NULL;

}
template<typename DataType>
int doubleLinkedList<DataType>::Empty()
{
	return head->next == NULL;
}

template<typename DataType>
void doubleLinkedList<DataType>::Print()
{
	doubleNode<DataType>* p = head->next;
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
int doubleLinkedList<DataType>::Length()
{
	doubleNode<DataType>* p = head->next;
	int count = 0;
	while (p != NULL)
	{

		p = p->next;
		count++;
	}
	return count;
}

template<typename DataType>
DataType doubleLinkedList<DataType>::Get(int i)
{
	doubleNode<DataType>* p = head->next;
	int count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw std::runtime_error{"Index Error"};
	else return p->data;
}

template<typename DataType>
int doubleLinkedList<DataType>::Find(DataType x)
{
	doubleNode<DataType>* p = head->next;
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
void doubleLinkedList<DataType>::Insert(int i, DataType x)
{
	doubleNode<DataType>* p = head, * s = NULL;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL) return;
	s = new doubleNode<DataType>;
	s->data = x;
	if (p->next != NULL)
		p->next->prior = s;
	s->next = p->next;
	s->prior = p;
	p->next = s;
}


template<typename DataType>
doubleLinkedList<DataType>::doubleLinkedList(DataType a[], int n)
{
	head = new doubleNode<DataType>;
	doubleNode<DataType>* r = head, * s = NULL;


	for (int i = 0; i < n; i++)
	{
		s = new doubleNode<DataType>; s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
template<typename DataType>
DataType doubleLinkedList<DataType>::Delete(int i)
{
	DataType x;
	doubleNode<DataType>* p = head, * q = NULL;
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
		if (p->next != NULL && p->next != nullptr)
		{
			p->next = q->next;
			p->next->prior = p;
		}
		delete q;
		return x;
	}
}

template<typename DataType>
doubleLinkedList<DataType>::~doubleLinkedList()
{
	doubleNode<DataType>* p = head;
	while (head != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
}
template<typename DataType>
void doubleLinkedList<DataType>::Clear()
{
	while (head->next != NULL) 
	{
		auto p = head->next;
		head->next = p->next;
		delete p;
	}
}

