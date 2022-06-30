#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
    double num1,num2,num3,mmax,mmin,average;
    
    cin>>num1>>num2>>num3;

    average=num1+num2+num3/3;
    mmax=max(max(num1,num2),num3);
    mmin=min(min(num1,num2),num3);

    cout<<setw(8)<<setfill(' ')<<fixed<<setprecision(4)<<setiosflags(ios::left)<<average;
    cout<<setw(6)<<setfill(' ')<<fixed<<setprecision(4)<<setiosflags(ios::right)<<mmax;
    cout<<setw(6)<<setfill(' ')<<fixed<<setprecision(4)<<setiosflags(ios::right)<<mmin;
    
    system("pause");
    return 0;
}