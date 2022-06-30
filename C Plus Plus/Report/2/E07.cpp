#include<iostream>
using namespace std;
int main()
{
    int a,n,sum=0;
    int x;
    cout<<"请输入a和n"<<endl;
    cin>>a>>n;
    x=a;
    for(int i=1;i<=n;i++)
    {
        sum+=a;
        a=a*10+x;
    }
    cout<<"sum="<<sum<<endl;
    system("pause");
    return 0;
}
