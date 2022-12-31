#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
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
		cout<<p->data<<",";
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
	string line;
	getline(cin,line);
	for(auto &i:line)if(i==',') i=' ';
	stringstream source(line);

	int n=0;
	while(source>>a[n])
	{
	
		n++;
	}
		
		
	n--;
	LinkList<int> L(a,n+1);
//	L.print();


	while(getline(cin,line))
	{
		for(auto &i:line)if(i==',') i=' ';
		stringstream source(line);
		vector<int>temp;
		int t,aa,m;
		while(source>>t)temp.push_back(t);
		if(temp.size()==2)
		{
			aa=temp[0],m=temp[1];
			if(aa==1)
			{
				
				for(int i=1;i<=m;i++)
				{
					int num= L.Delete(L.Length());
					L.Insert(2*i,num);
				}
			}
			else if (aa==2)
			{
				
				int l=min(L.Length()-m-1,m+1);
		//		cout<<"l="<<l<<endl;
				vector<int>v;
				for(int i=1;i<=l;i++)
				{
					v.push_back(L.Delete(m+2));
				};
				for(int i=1;i<=l;i++)
				{
					L.Insert(2*i,v.front());
					v.erase(v.begin());
				}
			}
			else if (aa==3)
			{
				int count=0,key;
				key=m;
				while(L.Locate(key))
				{
					L.Delete(L.Locate(key));
					count++;			
				}
				for(int i=1;i<=count;i++)
					L.Insert(L.Length()+1,key);
				
			}
			L.print();
		}
		else if (temp.size()==1&&temp[0]==-1)continue;
		else
		{
			while(!L.Empty())L.Delete(1);
			int n=0;
			for(int i=0;i<(int)temp.size();i++)
			{
				a[i]=temp[i];
				n++;
			}
			n--;
			
		}
	
		
	}
	return 0;
}
