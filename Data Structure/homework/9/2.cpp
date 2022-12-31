//fw
#include<bits/stdc++.h>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define endl '\n'
using namespace std;
typedef long long ll;

struct node
{
	int data;
	node *lc,*rc;
	node(int d)
	{
		data=d;
		lc=NULL;
		rc=NULL;
	}
};
class BinaryTree
{
private:
	node *root;
public:
	int cnt=0;
	BinaryTree(vector<int>a)
	{
		root=create(a,0,a.size());
	}
	~BinaryTree()
	{
		DeleteTree(root);
	}
	node* create(vector<int>a,int start,int end)
	{
		if(start>=end)
		{
			return NULL;
		}
		int maxNum=-0x3f3f3f3f,p=0;
		for(int i=start;i<end;i++)
		{
			if(a[i]>maxNum)
			{
				maxNum=a[i];
				p=i;
			}
			cnt++;
		}
		node *temp=new node(maxNum);
		temp->lc=create(a,start,p);
		temp->rc=create(a,p+1,end);
		return temp;
	}
	void DeleteTree(node *bt)
	{
		if(bt->lc)DeleteTree(bt->lc);
		if(bt->rc)DeleteTree(bt->rc);
		delete(bt);
	}
	node * Get()
	{
		return root;
	}
	void print(node *bt)
	{
		if(bt==NULL)return;
		cout<<bt->data<<" ";
		print(bt->lc);
		print(bt->rc);
	}
};
int main()
{
	vector<int>a;
	int  n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	BinaryTree T(a);
	T.print(T.Get());

	return 0;
}
