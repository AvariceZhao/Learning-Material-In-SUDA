#pragma once
#include"doubleLinkedListNode.h"
template<typename DataType>
class doubleCircularLinkedList
{
public:
	doubleCircularLinkedList();
	~doubleCircularLinkedList();
	doubleCircularLinkedList(DataType a[], int n);
	bool Empty();
	int Length();
	void Print();
	DataType Get(int i);
	void Insert(int index, DataType elem);
	int Find(DataType x);
	DataType Delete(int i);
	void Clear();
private:
	doubleNode<DataType>* head;
};
template<typename DataType>
doubleCircularLinkedList<DataType>::doubleCircularLinkedList()
{
	head = new doubleNode<DataType>;
	head->data = NULL;
	head->next = head;
	head->prior = head;
}
template<typename DataType>
doubleCircularLinkedList<DataType>::~doubleCircularLinkedList()
{
	doubleNode<DataType>* p;
	while (head->next != head)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}
}
template<typename DataType>
doubleCircularLinkedList<DataType>::doubleCircularLinkedList(DataType a[], int n)
{
	head = new doubleNode<DataType>;
	doubleNode<DataType>* p = head;
	for (int i = 0; i < n; i++)
	{
		doubleNode<DataType>* s = new doubleNode<DataType>;

		s->data = a[i];
		s->next = head;
		p->next = s;
		p = s;
	}
	std::cout << "创建成功！" << std::endl;


}
template<typename DataType>
bool doubleCircularLinkedList<DataType>::Empty()
{
	return head->next == head;
}
template<typename DataType>
int doubleCircularLinkedList<DataType>::Length()
{
	doubleNode<DataType>* p = head;
	int cnt = 0;
	while (p->next != head)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}
template<typename DataType>
void doubleCircularLinkedList<DataType>::Print()
{
	doubleNode<DataType>* p = head;
	while (p->next != head)
	{
		p = p->next;
		std::cout << p->data << " ";

	}
	std::cout << std::endl;
}
template<typename DataType>
DataType doubleCircularLinkedList<DataType>::Get(int index)
{
	doubleNode<DataType>* p = head->next;
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
void doubleCircularLinkedList<DataType>::Insert(int index, DataType elem)
{
	doubleNode<DataType>* p = head;
	doubleNode<DataType>* s = new doubleNode<DataType>;
	int j = 1;
	while (p->next != head && j < index)
	{
		p = p->next;
		j++;
	}
	if (p->next == head || j > index)
		throw std::runtime_error{ "index error" };

	s->data = elem;
	p->next->prior = s;
	s->next = p->next;
	s->prior = p;
	p->next = s;
}
template<typename DataType>
DataType doubleCircularLinkedList<DataType>::Delete(int index)
{
	doubleNode<DataType>* p = head;
	doubleNode<DataType>* s = new doubleNode<DataType>;
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
	s->next->prior = p;
	p->next = s->next;

	delete s;
	return delete_data;
}
template<typename DataType>
int doubleCircularLinkedList<DataType>::Find(DataType x)
{
	doubleNode<DataType>* p = head->next;
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
void doubleCircularLinkedList<DataType>::Clear()
{
	while (head->next != head)
		Delete(1);
}
