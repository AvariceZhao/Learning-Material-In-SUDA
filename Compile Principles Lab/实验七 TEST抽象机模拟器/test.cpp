#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Array
{
    T *m_parray;
    int m_len;
    public:
    Array(int n)
    {
        if(!n) m_parray=0;
        else
        {
            m_parray=new T[n+1];
            m_len=n;
            for(int i=0;i<=n;i++)
                m_parray[i]=0;
        }
    }
    Array()
    {
        if(m_parray!=0)delete []m_parray;

    }
    T &operator[](int index)
    {
        if(index<0||index>m_len)
        {
            throw std::runtime_error("out of index");
        }
        else
        {
            return m_parray[index];
        }
    }

};
const int MAXN=1000;
int main()
{
  //ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    
    Array<int> array1(MAXN);
    array1[2]=9;
    int x = array1[2000];
    //   system("pause");
    return 0;
}