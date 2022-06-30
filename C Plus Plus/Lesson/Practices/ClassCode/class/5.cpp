#include<bits/stdc++.h>
using namespace std;
void test()
{
    int num1=0;
    static   int num2=0;
    num1++;
    num2++;
    cout<<num1<<" "<<num2<<endl;

}
int main()
{
  //ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    for(int i=0;i<3;i++)
    test();
    system("pause");
    return 0;
}