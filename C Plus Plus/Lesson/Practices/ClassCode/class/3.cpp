#include<bits/stdc++.h>
using namespace std;
class CSafeArray
{
    int *m_parray;
    int m_len;
    public:
    CSafeArray(int n)
    {
        if(!n) m_parray=0;
        else
        {
            m_parray=new int[n+1];
            m_len=n;
            for(int i=0;i<=n;i++)
                m_parray[i]=0;
        }
    }
    ~CSafeArray()
    {
        if(m_parray!=0)delete []m_parray;

    }
    int &operator[](int index)
    {
        if(index<0||index>=m_len)
        {
                return m_parray[m_len];
        }
        else
        {
            return m_parray[index];
        }
    }
   // friend int main();
};
int main()
{
  //ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    CSafeArray array1(10);
    array1[2]=9;
 //   array1.m_len=15;
   // cout<<array1.m_len<<endl;
    cout<<array1[2]<<" "<<array1[2000];

    return 0;
}