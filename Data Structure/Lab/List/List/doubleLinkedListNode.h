#pragma once
template<typename Entry>
struct doubleNode
{
	Entry data;
	doubleNode<Entry>* prior;
	doubleNode<Entry>* next;
	doubleNode()
	{
		next = NULL;
	}
	doubleNode(Entry t, doubleNode<Entry>* link, doubleNode<Entry> *link1)
	{
		data = t;
		next = link1;
		prior = link;
	}
};