#include<iostream>
using namespace std;
template<typename data_type>
struct LinkNode
{
	data_type data;
	LinkNode<data_type>* next;
};
template<typename data_type>
class Queue
{
	public:
		Queue();
		~Queue();
		bool empty();
		data_type front();
		void push(data_type item);
		void pop();
		int size();
	private:
		LinkNode<data_type>* Front, * Rear;
		int _size = 0;
};
template<typename data_type>
int Queue<data_type>::size()
{
	return _size;
}
template<typename data_type>
Queue<data_type>::Queue()
{
	LinkNode<data_type>* s = NULL;
	s = new LinkNode<data_type>;
	s->next = NULL;
	Front = Rear = s;
}
template<typename data_type>
Queue<data_type>::~Queue()
{
	while (!empty())
		pop();
	_size = 0;
}
template<typename data_type>
bool Queue<data_type>::empty()
{
	return Front == Rear;
}
template<typename data_type>
void Queue<data_type>::push(data_type  item)
{
	LinkNode<data_type> * s = NULL;
	s = new LinkNode<data_type>;
	s->data = item;
	s->next = NULL;
	Rear->next = s;
	Rear = s;
	_size++;
}
template<typename data_type>
void Queue<data_type>::pop()
{
	LinkNode<data_type> *p = NULL;
	p = Front->next;
	Front->next = p->next;
	if (p->next == NULL) Rear = Front;
	delete p;
	_size--;
}
template<typename data_type>
data_type Queue<data_type>::front()
{
	data_type x = Front->next->data;

	return x;
}

template<typename DataType>
struct BinaryNode
{
	DataType data;
	BinaryNode<DataType>* lchild, * rchild;
	BinaryNode()
	{
		data = 0;
		lchild = NULL;
		rchild = NULL;
	}
	BinaryNode(DataType d)
	{
		data = d;
		lchild = NULL;
		rchild = NULL;
	}
};
template<typename DataType>
class BinaryTree
{
	public:
		BinaryTree()
		{
			root = Create();
		}
		~BinaryTree()
		{
			DestoryTree(root);
		}
		void PreOrder();
		void InOrder();
		void PostOrder();
		void LevelOrder();
		int GetDepth();
		int GetWidth();
		int CalcDegree(int degree);
		bool QuerySum(int sum)
		{
			return querySumRecursion(root, sum);
		}

	private:
		BinaryNode<DataType>* root;
		BinaryNode<DataType>* Create();
		void DestoryTree(BinaryNode<DataType>* rt);
		void PreOrderRecursion(BinaryNode<DataType>* rt);
		void InOrderRecursion(BinaryNode<DataType>* rt);
		void PostOrderRecursion(BinaryNode<DataType>* rt);
		int GetDepthRecursion(BinaryNode<DataType>* rt);
		int CalcDegreeRecursion(BinaryNode<DataType>* rt, int degree);
		bool querySumRecursion(BinaryNode<DataType>* rt, int sum);
};
template<typename DataType>
bool BinaryTree<DataType>::querySumRecursion(BinaryNode<DataType>* rt, int sum)
{
	if (rt == NULL || sum < 0)return false;
	if (rt->data == sum || rt->data == 0)return true;
	return (querySumRecursion(rt->lchild, sum - rt->data) || querySumRecursion(rt->rchild, sum - rt->data));
}
template<typename DataType>
int BinaryTree<DataType>::GetDepth()
{
	return GetDepthRecursion(root) - 1;
}
template<typename DataType>
int BinaryTree<DataType>::GetDepthRecursion(BinaryNode<DataType>* rt)
{
	return rt == NULL ? 0 : 1 + GetDepthRecursion(rt->lchild) + GetDepthRecursion(rt->rchild);
}

template<typename DataType>
BinaryNode<DataType>* BinaryTree<DataType>::Create()
{
	DataType data;
	std::cin >> data;
	if (data == '#')return NULL;
	BinaryNode<DataType>* temp = new BinaryNode<DataType>(data);
	temp->lchild = Create();
	temp->rchild = Create();
	return temp;
}
template<typename DataType>
void BinaryTree<DataType>::DestoryTree(BinaryNode<DataType>* rt)
{
	if (rt == NULL)return;
	DestoryTree(rt->lchild);
	DestoryTree(rt->rchild);
	delete rt;
}
template<typename DataType>
void BinaryTree<DataType>::PreOrder()
{
	std::cout << "当前二叉树的前序遍历为:" << std::endl;
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
	std::cout << "当前二叉树的中序遍历为:" << std::endl;
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
	std::cout << "当前二叉树的后序遍历为:" << std::endl;
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
	Queue<BinaryNode<DataType>* >Q;
	Q.push(root);

	std::cout << "当前二叉树的层序遍历为:" << std::endl;
	while (!Q.empty())
		{
		BinaryNode<DataType>* t = Q.front();
		Q.pop();
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
		maxWidth = std::max(maxWidth, levelWidth);
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
	if (k < 0 || k > 2)return 0;
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
int main()
{
	BinaryTree<int>T;
	int x;
	cin >> x;
	cout << T.QuerySum(x) << endl;
	return 0;
}
