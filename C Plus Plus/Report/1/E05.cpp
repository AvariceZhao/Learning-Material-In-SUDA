#include<iostream>
using namespace std;
int main()
{
    int distance;
    double t;

    cin>>distance;
    
    t= distance*1.0/1.2;
    
    if((50+distance*1.0/3.0)>t)
        {
            cout<<"步行快";
        }
    if((50+distance*1.0/3.0)<t)
        {
            cout<<"骑车快";
        }
    if((50+distance*1.0/3.0)==t)
        {
            cout<<"一样快";
        }
    return 0;
}