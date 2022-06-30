#include<bits/stdc++.h>
using namespace std;

class CMYString
{
	char *m_pstr;
	public :
		void addString(const char *str)
		{
			int mlen=0,len=0;
			
			if(m_pstr) mlen=strlen(m_pstr);
			if(str)len=strlen(str);
			char *tmp=new char [mlen+len+1];
			if(mlen)strcpy(tmp,m_pstr);
			if(len)strcpy(tmp+mlen,str);
			if(m_pstr)delete m_pstr;
			m_pstr=tmp;
			
		}
		void addString(const CMYString &str)
		{
			char *tmp=str.m_pstr;
			addString(tmp);
		}
		CMYString(const char *str)
		{
		
		m_pstr=new char[strlen(str)+1];
		strcpy(m_pstr,str);
		}
		CMYString()
		{
			m_pstr=0;
		}
		CMYString (const CMYString &temp)
		{
			if(temp.m_pstr==0)
			this->m_pstr=0;
			else
			{
			m_pstr=new char[strlen(temp.m_pstr)+1];
			strcpy(m_pstr,temp.m_pstr);
			}
		}
		~CMYString()
		{
				
				if(m_pstr)delete []m_pstr;
		}
		
	void setString(const char *str)
	{
		if(m_pstr)delete []m_pstr;
		m_pstr=new char[strlen(str)+1];
		strcpy(m_pstr,str);
		
	}
	void display()
	{   if(m_pstr!=0)
		cout<<m_pstr<<endl;
	}
	void operator=(const CMYString &temp)//如果需要写拷贝构造函数，一般要写赋值运算符重载
	{	
			if(m_pstr)
			delete m_pstr;

			if(temp.m_pstr==0)
			this->m_pstr=0;
			else
			{
			m_pstr=new char[strlen(temp.m_pstr)+1];
			strcpy(m_pstr,temp.m_pstr);
			}
	}
};
int main()
{
	CMYString str1;
	str1.setString("苏州大学");
		str1.display();
	CMYString str3;
	str3=str1;
	str3.display();
	str1.addString("123");
		str1.display();
	system("pause");
	return 0;
}
