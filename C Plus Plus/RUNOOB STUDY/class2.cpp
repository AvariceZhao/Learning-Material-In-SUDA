#include<bits/stdc++.h>
using namespace std;
class line{//һ����˽�����������ݣ��ڹ��������庯�� 
	public:
		int public1;
		void set1(int p1);
		void set2(int p2);
		void printp1();
	private:
		int private1;
	
		
	protected://��private���ƣ���protected���������ǿɷ��ʵ� ����private���ܱ�������� 
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
