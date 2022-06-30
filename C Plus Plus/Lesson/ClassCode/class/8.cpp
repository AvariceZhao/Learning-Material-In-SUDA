//fw
#include<bits/stdc++.h>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define endl '\n'
using namespace std;
typedef long long ll;
class Grandam {
public:
	virtual void introduce_self()  // 定义虚函数introduce_self()
	{ cout<<"I am grandam."<<endl; }
};
class Mother:public Grandam {
public:
	virtual	void introduce_self()     // 重新定义虚函数introduce_self()
	{ cout<<"I am mother."<<endl;}
};
class Daughter:public Mother {
public:
		virtual void introduce_self()     // 重新定义虚函数introduce_self()
	{ cout<<"I am daughter."<<endl;}
};
int main()
{
	Grandam *ptr;
	Grandam g;
	Mother m;
	Daughter d;
	ptr=&g;
	ptr->introduce_self();
	ptr=&m;
		ptr->introduce_self();
	ptr=&d;
		ptr->introduce_self();
	return 0;
}
