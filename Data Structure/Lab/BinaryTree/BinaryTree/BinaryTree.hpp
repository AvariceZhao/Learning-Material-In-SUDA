#pragma once
#include<iostream>
#include"LinkQueue.hpp"
#include"BinaryNode.h"
template<typename DataType>
class BinaryTree
{
public:
    BinaryTree() { root = NULL; }
    ~BinaryTree() { DestoryTree(root); }
    void CreateTreeByPreOrder() { root = Create(); }
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
    int GetDepth();
    int GetWidth();
    int CalcDegree(int degree);
protected:
    BinaryNode<DataType>* root;
    BinaryNode<DataType>* Create();
    void DestoryTree(BinaryNode<DataType>* rt);
    void PreOrderRecursion(BinaryNode<DataType>* rt);
    void InOrderRecursion(BinaryNode<DataType>* rt);
    void PostOrderRecursion(BinaryNode<DataType>* rt);
    int GetDepthRecursion(BinaryNode<DataType>* rt);
    int CalcDegreeRecursion(BinaryNode<DataType>* rt, int degree);
};

template<typename DataType>
int BinaryTree<DataType>::GetDepth()
{
    return GetDepthRecursion(root)-1;
}
template<typename DataType>
int BinaryTree<DataType>::GetDepthRecursion(BinaryNode<DataType>* rt)
{
    return rt == NULL ? 0 : 1 +max( GetDepthRecursion(rt->lchild) ,GetDepthRecursion(rt->rchild));
}

template<typename DataType>
BinaryNode<DataType>* BinaryTree<DataType>::Create()
{
    DataType data;
    std::cin >> data;
    if (data == 0)return NULL;
    BinaryNode<DataType>* temp = new BinaryNode<DataType>(data);
    temp->lchild = Create();
    temp->rchild = Create();
    return temp;
}
template<typename DataType>
void BinaryTree<DataType>::DestoryTree(BinaryNode<DataType>* rt)
{
    if (rt == NULL)return;
  //  std::cout << rt->data << " " << std::endl;
    if(rt->lchild!=NULL)
    DestoryTree(rt->lchild);
    if(rt->rchild!=NULL)
    DestoryTree(rt->rchild);

    rt = NULL;
    
    delete rt;
}
template<typename DataType>
void BinaryTree<DataType>::PreOrder()
{
    std::cout << "The Preorder traversal of the tree is:" << std::endl;
    PreOrderRecursion(root);
    std::cout << std::endl;
}
template<typename DataType>
void BinaryTree<DataType>::PreOrderRecursion(BinaryNode<DataType>* rt)
{
    if (rt == NULL)return;
    std::cout << rt->data << " ";
    PreOrderRecursion(rt->lchild);
    PreOrderRecursion(rt->rchild);
}

template<typename DataType>
void BinaryTree<DataType>::InOrder()
{
    std::cout << "The Inorder traversal of the tree is" << std::endl;
    InOrderRecursion(root);
    std::cout << std::endl;
}
template<typename DataType>
void BinaryTree<DataType>::InOrderRecursion(BinaryNode<DataType>* rt)
{
    if (rt == NULL)return;
    InOrderRecursion(rt->lchild);
    std::cout << rt->data << " ";
    InOrderRecursion(rt->rchild);
}

template<typename DataType>
void BinaryTree<DataType>::PostOrder()
{
    std::cout << "The Postorder traversal of the tree is:" << std::endl;
    PostOrderRecursion(root);
    std::cout << std::endl;
}
template<typename DataType>
void BinaryTree<DataType>::PostOrderRecursion(BinaryNode<DataType>* rt)
{
    if (rt == NULL)return;
    PostOrderRecursion(rt->lchild);
    PostOrderRecursion(rt->rchild);
    std::cout << rt->data << " ";
}
template<typename DataType>
void BinaryTree<DataType>::LevelOrder()
{


    std::cout << "The Levelorder traversal of the tree is:" << std::endl;
    Queue<BinaryNode<DataType>* >Q;
    Q.push(root);
    while (!Q.empty())
    {
        BinaryNode<DataType>* t = Q.front(); Q.pop();
        std::cout << t->data << " ";
        if (t->lchild != NULL)Q.push(t->lchild);
        if (t->rchild != NULL)Q.push(t->rchild);
    }
    std::cout << std::endl;
}
template<typename DataType>
int BinaryTree<DataType>::GetWidth()
{
    Queue<BinaryNode<DataType>* >Q;
    int maxWidth = 0;
    if (root != NULL)Q.push(root);
    while (!Q.empty())
    {
        int levelWidth = Q.size();
        maxWidth = max(maxWidth, levelWidth);
        for (int i = 0; i < levelWidth; i++)
        {
            BinaryNode<DataType>* p = Q.front();
            if (p->lchild != NULL)Q.push(p->lchild);
            if (p->rchild != NULL)Q.push(p->rchild);
            Q.pop();
        }
    }
    return maxWidth;
}
template<typename DataType>
int BinaryTree<DataType>::CalcDegree(int k)
{
    if (k < 0 || k>2)return 0;
    return CalcDegreeRecursion(root, k);
}
template<typename DataType>
int BinaryTree<DataType>::CalcDegreeRecursion(BinaryNode<DataType>* rt, int degree)
{
    if (rt == NULL)return 0;
    int child = 0;
    if (rt->lchild != NULL)child++;
    if (rt->rchild != NULL)child++;
    return degree == child ? 1 + CalcDegreeRecursion(rt->lchild, degree) + CalcDegreeRecursion(rt->rchild, degree) 
        : CalcDegreeRecursion(rt->lchild, degree) + CalcDegreeRecursion(rt->rchild, degree);
}
