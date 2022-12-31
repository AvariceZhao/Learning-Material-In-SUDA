#pragma once
template<typename data_type>
struct Node
{
    data_type data;
    Node<data_type>* next;
};