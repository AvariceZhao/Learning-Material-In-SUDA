#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;
class stack
{
	private:
			double stk[100000]={0};
			int Bottom=0;
			int Top=-1;
	public:
			void push(double u)
			{
				stk[++Top]=u;
			}
			void pop()
			{
				Top--;
			}
			bool empty()
			{
				return Top<Bottom;
			}
			double top()
			{
				return stk[Top];
			}
  
};
double prefix(string prefix_ex[], int n) 
{
	stack stk;
	n--;
	for(int i=n;i>=0;i--)
	{
		string temp=prefix_ex[i];
	
		if(temp=="+"||temp=="-"||temp=="*"||temp=="/")
		{
			if(stk.empty())
			{
				cout<<"illegal expression"<<endl;
				exit(0);
				
			}
			else
			{
				double number1=stk.top();
				stk.pop();
				if(stk.empty())
				{
				cout<<"illegal expression"<<endl;
				exit(0);
				}
			else
				{
				double number2=stk.top();
				stk.pop();
				
				if(temp=="+") stk.push(number1+number2);
				
				else if (temp=="-") stk.push(number1-number2);
				
				else if (temp=="*") stk.push(number1*number2);
				
				else stk.push(number1/number2);
				
				}
				
			}
		}
		else
		{
			stringstream ss(temp);
			double num;
			ss>>num;
			stk.push(num);
		}
	}
	return stk.top();
}
int main() 
{

string prefix_ex;           

getline(cin,prefix_ex);

string prefix_array[20];

stringstream ss(prefix_ex);

int i = 0;

while (ss >> prefix_array[i])

    i++;

cout << prefix(prefix_array, i) << endl;

}