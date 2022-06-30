#include<bits/stdc++.h>
using namespace std;
class CA{
    int m_x;
    public :
    CA(int i=0)
    {
        m_x=i;
    }
    friend int main();
};
int main()
{
  //ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    CA a;

    a.m_x=20;
    cout<<a.m_x<<endl;

    return 0;
}