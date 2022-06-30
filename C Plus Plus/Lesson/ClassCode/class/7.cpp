//fw
#include<bits/stdc++.h>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define endl '\n'
using namespace std;
typedef long long ll;
class B0{
public:
	void display()
	{
		cout<<"B0::Display"<<endl;
	}
};
class B1:public B0
{
	public:
		void display()
		{
			cout<<"B1::Display"<<endl;
		}
};
int main()
{
	//ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	B0 b0;
	B1 b1;
	B0 *p;
	B1 *q;
	p=&b1;
	q=&b1;
//	b1.display();
//	b0.display();
//	p->display();
//	q->display();
	B0 &r=b1;
	r.display();
	return 0;
}
