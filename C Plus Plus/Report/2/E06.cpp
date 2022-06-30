#include<iostream>
using namespace std;
int main()
{   int cnt=0;
    for(int i=32;i<=126;i++)
    {   cout<<(char)i<<" ";
        cnt++;
        if(cnt==5)
        {
       cout<<endl;
            cnt=0;
        }
}
return 0;
}
