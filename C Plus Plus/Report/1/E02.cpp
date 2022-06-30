#include<iostream>
using namespace std;
int main()
{
	char c;

    cout<<"请输入一个字符"<<endl;
	cin>>c;

	if(c>='A'&&c<='Z')
	{
        cout<<(char)(c+32)<<endl;
    }
    else if (c>='a'&&c<='z')
	{
        cout<<(char)(c-32)<<endl;
    }
    else
	{
        cout<<c<<endl;
    }
    return 0;
}