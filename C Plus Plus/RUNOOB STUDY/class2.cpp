#include<bits/stdc++.h>
using namespace std;
class line{//一般在私有区域定义数据，在公有区域定义函数 
	public:
		int public1;
		void set1(int p1);
		void set2(int p2);
		void printp1();
	private:
		int private1;
	
		
	protected://与private类似，但protected在子类中是可访问的 。但private不能被子类访问 
		int protect1;
		void set3(int p3);
};
void line::printp1()
{
	cout<<private1;
}
void line::set1(int p1)
{
	public1=p1;
}
void line::set2(int p2)
{
	private1=p2;
}
void line::set3(int p3)
{
	protect1=p3;
}
int main()
{line a;
a.set1(5);
a.set2(6);
a.printp1();
	
 } 
