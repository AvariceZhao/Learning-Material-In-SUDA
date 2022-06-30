#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	float b;
	double c;
	long d;
	char e;
	string f;
	bool g;
};
int main()
{	node t;
	node *p;
	p=&t;
	p->a=1;
	
	cout<<p->a;
	return 0;
	
 } 
