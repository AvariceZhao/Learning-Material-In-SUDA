#include<bits/stdc++.h>
using namespace std;
class box
{
    double width;
    public:
    double length;
    friend void printwidth(box b);
    void setwidth(double wid);
    ~box();
};
void box::setwidth(double wid)
{
width=wid;
}
box::~box()
{
	cout<<"The box is deleted";
}
void printwidth(box b)
{
    cout<<"width of boxx is :"<<b.width<<endl;
}
int main()
{
    box boxx;
    boxx.setwidth(10.0);
    printwidth(boxx);
    return 0;
}
