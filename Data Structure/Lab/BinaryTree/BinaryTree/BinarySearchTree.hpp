#include"BinaryTree.hpp"
template<typename DataType>
class BinarySearchTree :public BinaryTree<DataType>
{
public:
	BinarySearchTree(DataType a[], int n);
	~BinarySearchTree() { this->DestoryTree(this->root); }
	bool InsertBST(const DataType x) { return InsertRecursion(this->root, x); }
	BinaryNode<DataType>* SearchBST(DataType x) { return SearchBST(this->root, x); };
	
	bool Remove(const DataType& x) { return RemoveRecursion(this->root, x); };
private:
	bool InsertRecursion(BinaryNode<DataType>*& bt, const DataType& x);
	BinaryNode<DataType>* SearchBST(BinaryNode<DataType>* bt, DataType x);
	bool RemoveRecursion(BinaryNode <DataType>*& rt, const DataType& x);
	void RemoveRoot(BinaryNode <DataType>*& rt);
};
template<typename DataType>
void BinarySearchTree<DataType>::RemoveRoot(BinaryNode <DataType>*& rt)
{
	BinaryNode<DataType>* toDelete = rt;
	if (rt->rchild == nullptr)
	{
		rt = rt->lchild; 
	}
	else if (rt->lchild == nullptr) 
	{
		rt = rt->rchild;
	}
	else
	{  
		toDelete = rt->lchild; 
		BinaryNode<DataType>* parent = rt;
		while (toDelete->rchild != nullptr) 
		{    
			parent = toDelete;
			toDelete = toDelete->rchild;
		} 
		rt->data = toDelete->data;
		if (parent == rt) 
		{
			rt->lchild = toDelete->lchild;
		}
		else 
		{
			parent->rchild = toDelete->lchild;
		}
	}
	delete toDelete;
}
template<typename DataType>
bool  BinarySearchTree<DataType>::RemoveRecursion(BinaryNode <DataType>*& rt, const DataType& x)
{
	if (rt == NULL) { return false; } 
	else if (rt->data == x) { 
		RemoveRoot(rt);
		return true;
	}
	else if (x < rt->data) {
		return RemoveRecursion(rt->lchild, x);
	}
	return RemoveRecursion(rt->rchild, x);
}
template<typename DataType>
BinaryNode<DataType>* BinarySearchTree<DataType>::SearchBST(BinaryNode<DataType>* bt, DataType x)
{
	if (bt == NULL)return NULL;
	if (bt->data == x)return bt;
	else if (bt->data > x)	return	SearchBST(bt->lchild, x);
	else return SearchBST(bt->rchild, x);

}
template<typename DataType>
BinarySearchTree<DataType>::BinarySearchTree(DataType a[], int n)
{

	this->root = NULL;

	for (int i = 0; i < n; i++)
		InsertBST(a[i]);


}
template<typename DataType>
bool BinarySearchTree<DataType>::InsertRecursion(BinaryNode<DataType>*& bt, const DataType& x)
{

	if (bt == nullptr)
	{
		bt = new BinaryNode<DataType>(x);
		return true;
	}
	else if (bt->data > x)
		return InsertRecursion(bt->lchild, x);

	else if (bt->data<x)
		return InsertRecursion(bt->rchild, x);
	return false;
}
