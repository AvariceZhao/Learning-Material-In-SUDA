#include<iostream>
using namespace std;
class CComplex{
	private:
		double m_real;
		double m_image;
	public:
		CComplex operator+(const CComplex b)const
		{
			return CComplex(m_real+b.m_real,m_image+b.m_image);
		}
		CComplex &operator ++ ()
		{
			setValue(m_real+1.0,m_image+1.0);
			return *this;
		}
		CComplex operator ++ (int i)
		{
			auto temp=*this;
			m_real+=1.0,m_image+=1.0;
			return temp;
		}
		CComplex operator+(const double b)const
		{
			return CComplex(m_real+b,m_image);
		}
	

		CComplex(double r=0,double i=0)
		{
			this->m_real=r;
			this->m_image=i;
		}
		void setValue(double real,double image)
		{
			m_real=real;
			m_image=image;
		}
		void add(const CComplex &complex)
		{
			m_real+=complex.m_real;
			m_image+=complex.m_image;
		}
		CComplex add(const double &temp)
		{

			m_real+=temp;
		}
		friend ostream &operator<<(ostream &out, CComplex temp)
		{
			cout<<temp.m_real<<"+"<<temp.m_image<<"*i"<<endl;
			return out;
		}

		void show();
};
int main()
{
	double x1,y1,x2,y2;
	CComplex c1,c2,c3;

	cout<<"输入四个实数:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	c1.setValue(x1,y1);
	c2.setValue(x2,y2);
	cout<<"复数c1: "<<c1<<endl;
	cout<<"复数c2: "<<c2<<endl;
	c3=c1+c2;
	cout<<"c1+c2: "<<c3<<endl;
	cout<<"c1+x2: "<<c1+x2<<endl;
	cout<<"++c2: "<<++c2<<endl;
	cout<<"c2++: "<<c2++<<endl;
	cout<<"c2: "<<c2<<endl;

	system("pause");
	return 0;
}
