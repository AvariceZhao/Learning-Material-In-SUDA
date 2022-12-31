#pragma once
template<typename Entry>
struct Node
{
	Entry data;
	Node<Entry>* next;
	Node()
	{
		next = NULL;
	}
	Node(Entry t, Node<Entry>* link)
	{
		data = t;
		next = link;
	}
};