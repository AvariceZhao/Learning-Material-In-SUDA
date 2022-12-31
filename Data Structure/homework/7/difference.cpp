#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N],b[N];
template<typename Entry>
struct Node
{
	Entry data;
	Node<Entry>*next;
	Node()
	{
		next=NULL;
	}
	Node(Entry t,Node<Entry> *link)
	{
		data=t;
		next=link;
	}
};
template<typename DataType>
class   LinkList
{
public:
	LinkList();
	LinkList(DataType a[],int len);
	~LinkList();
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i,DataType x);
	DataType Delete(int i);
	int Empty();
	void print();
private:
	Node<DataType> *head;
};
template<typename DataType>
LinkList<DataType>::LinkList()
{
	head=new Node<DataType>;
	head->next=NULL;
}
template<typename DataType>
int LinkList<DataType>::Empty()
{
	return head->next==NULL;
}

template<typename DataType>
void LinkList<DataType>::print()
{
	Node<DataType>* p=head->next;
	while(p!=NULL)
	{	if(p->next!=NULL)
		cout<<p->data<<" ";
		else
			cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

template<typename DataType>
int LinkList<DataType>::Length()
{
	Node<DataType>* p=head->next;
	int count=0;
	while(p!=NULL)
	{
		
		p=p->next;
		count++;
	}
	return count;
}

template<typename DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType>*p=head->next;
	int count=1;
	while(p!=NULL&&count<i)
	{
		p=p->next;
		count++;
	}
	if(p==NULL) return 0;
		//throw runtime_error{"Index Error"};
	else return p->data;
}

template<typename DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType> *p=head->next;
	int count=1;
	while(p!=NULL)
	{
		if(p->data==x)return count;
		p=p->next;
		count++;
	}
	return 0;
}
template<typename DataType>
void LinkList<DataType>::Insert(int i,DataType x)
{
	Node<DataType>*p=head,*s=NULL;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL) return ;
	s= new Node<DataType>;
	s->data=x;
	s->next=p->next;
	p->next=s;
}


template<typename DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
	head=new Node<DataType>;
	Node<DataType>*r=head,*s=NULL;
	
	
	for(int i=0;i<n;i++)
	{
		s=new Node<DataType>;s->data=a[i];
		r->next=s;r=s;
	}
	r->next=NULL;
}
template<typename DataType>
DataType LinkList<DataType>::Delete(int i)
{
	DataType x;
	Node<DataType>*p=head,*q=NULL;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL||p->next==NULL)
		throw runtime_error{"Delete Index Error"};
	else
	{
		q=p->next;x=q->data;
		p->next=q->next;
		delete q;
		return x;
	}
}
template<typename DataType>
LinkList<DataType>::~LinkList()
{
	Node<DataType> *p=head;
	while(head!=NULL)
	{
		head=head->next;
		delete p;
		p=head;
	}
}

int main()
{
	string A,B;
	int cnt1=0,cnt2=0;
	getline(cin,A);
	
	getline(cin,B);
	stringstream  iA(A),iB(B);
	while(iA>>a[cnt1++]){};
	while(iB>>b[cnt2++]){};
	cnt1--;cnt2--;
	LinkList<int> LA(a,cnt1),LB(b,cnt2);
	for(int i=0;i<cnt1;i++)
	if(LB.Locate(a[i])==0)
	cout<<a[i]<<" ";
	return 0;
}
