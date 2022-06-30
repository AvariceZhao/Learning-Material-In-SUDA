#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int var1;
char var2[10];
char *p[10]; 
void get1(unsigned long *par);
int* func()
int main()
{	int *n=NULL;
	cout<<*&var1<<endl;
	cout<<*&var2<<endl;
	cout<<n<<endl;
	int var[3]={100,200,300};
	int *ptr;
	ptr=var;
	for(int i=0;i<3;i++)
	{
		cout<<"Adress of var["<<i<<"]=";
		cout<<ptr<<endl;
		cout<<"value of var["<<*ptr<<"]=";
		cout<<*ptr<<endl;
		ptr++; 
	}
	ptr=var;
	int i=0;
	while(ptr<&var[2])
	{cout<<"Adress of var["<<i<<"]=";
		cout<<ptr<<endl;
		cout<<"value of var["<<*ptr<<"]=";
		cout<<*ptr<<endl;
		ptr++; 
		i++;
		
	}
	
	int var1=5;
	int *p1;
	int **p2;
	p1=&var1;
	p2=&p1;
	cout<<"¶à¼¶Ö¸Õë"<<var1<<" "<<*p1<<" "<<**p2<<endl;;
	
	
	unsigned long s;
	get1(&s);
	cout<<s<<endl;
	return 0;
}
void get1(unsigned long *par)
{
	*par=time(NULL);
	return;
}
