#include<bits/stdc++.h>
using namespace std;
class Ccomplex{
	private:
		double m_real;
		double m_image;
	
	public:
		Ccomplex operator+(const Ccomplex b)const
		{
			return Ccomplex(m_real+b.m_real,m_image+b.m_image);
		}
		//前后置++既可以成员重载也可以友元
		Ccomplex &operator ++ ()//前置++ 通常返回引用
		{
			setInfo(m_real+1.0,m_image+1.0);
			return *this;
		}
		Ccomplex operator ++ (int i)//后置++
		{	
			auto temp=*this;
			m_real+=1.0,m_image+=1.0;
			return temp;
		}
		Ccomplex operator+(const double b)const
		{
			return Ccomplex(m_real+b,m_image);
		}
		Ccomplex operator-(const Ccomplex b)const
		{
			return Ccomplex(m_real-b.m_real,m_image-b.m_image);
		}
		
		Ccomplex(double r=0,double i=0)
		{
			this->m_real=r;
			this->m_image=i;
		}
		void setInfo(double real,double image)
		{
			m_real=real;
			m_image=image;
		}
		void add(const Ccomplex &complex)
		{
			m_real+=complex.m_real;
			m_image+=complex.m_image;
		}
		Ccomplex add(const double &temp)
		{
			
			m_real+=temp;
		}
		// friend ostream &operator<<(ostream &out, Ccomplex temp)
		// {
		// 	cout<<temp.m_real<<"+"<<temp.m_image<<"*i"<<endl;
		// 	return out;
		// }
		 ostream &operator<<(ostream &out)
		{
			out<<temp.m_real<<"+"<<temp.m_image<<"*i"<<endl;
			return out;
		}
		
		
		void show();
};

void Ccomplex::show()
{       if(m_image>=0)
		cout<<m_real<<"+"<<m_image<<"*i"<<endl;
		else 
			cout<<m_real<<m_image<<"*i"<<endl;

}
int main()
{
	Ccomplex c1(3,7);
	cout<<c1++<<endl;
	
	return 0;
}
