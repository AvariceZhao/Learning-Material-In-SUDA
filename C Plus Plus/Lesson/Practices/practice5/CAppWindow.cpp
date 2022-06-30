#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class CButton
{
private:
int m_width; // Button�Ŀ�ȣ���Χ:[50,500],��λ������
int m_high; // Button�ĸ߶ȣ���Χ:[25,250],��λ������
string m_name; // Button������
public:
CButton(int width= 100, int high= 50, const string & name= "NULL"); // ��Ĭ�ϲ���ֵ�Ĺ��캯��
string getName()const; //��ȡButton���ֵĳ���Ա����
void setName(const string&); // ����Button���ֵĳ�Ա����
friend ostream& operator<<(ostream &out,const CButton &temp)
{
    out<<"������Ϣ(���ߡ�����)��";
    out<<right<<setw(4)<<temp.m_width;
    out<<right<<setw(4)<<temp.m_high;
    out<<right<<setw(4)<<temp.m_name;
    return out;
}
};
CButton::CButton(int width,int high,const string &name):m_width(width),m_high(high),m_name(name){};
string CButton::getName()const{return m_name;}
void CButton::setName(const string &name)
{
    m_name=name;
}



class CWindow
{
private:
int m_width; // ���ڵĿ��Ǹ���������λ������
int m_hight; // ���ڵĸߣ��Ǹ���������λ������
public:
CWindow(int width= 500, int high= 400):m_width(width),m_hight(high){};
void zoom(int); // ���Ŵ���
friend ostream & operator<<(ostream &out,const CWindow &temp)
{
    out<<"������Ϣ(����)��";
    out<<setw(4)<<temp.m_width;
    out<<setw(4)<<temp.m_hight;
    return out;
}
};
void CWindow::zoom(int percent)
{
    double siz=percent/100;
    m_width*=siz;
    m_hight*=siz;
}
class CAppWindow:public CWindow
{
    private:
    vector<CButton> m_Button;
    string m_txt;
    public:
    CAppWindow(int buttonNum=2,string text="NULL",int width=500,int height=400):CWindow(width,height),m_txt(text)
    {
        m_Button.push_back({100,50,"��С��"});
        m_Button.push_back({100,50,"�ر�"});
        for(int i=0;i<buttonNum-2;i++)
        m_Button.push_back({});       
    };
    CAppWindow  & operator++()
    {
        m_Button.push_back({120,60,"���"});
        return (*this);
    }
    CAppWindow operator --(int)
    {
        auto t=(*this);
        if(m_Button.size()>2)
        {
            m_Button.pop_back();
        }
        else
        {
            cout<<"�����а���ɾ������";
        }
        return t;
    }
    char & operator[](int index)
    {
        int len=m_txt.size();
        if(index<0||index>=len)
        {
            cout<<"����Խ��"<<endl;
            return m_txt[0];
        }
        else 
            return m_txt[index];
    }
    void setButtonName(int x,string name)
    {
        if(x<2)
        {
            cout<<"�������޸�����"<<endl;
            return;
        }
        else
        {
            m_Button[x].setName(name);
        }
    }
    friend ostream & operator<<(ostream &out,const CAppWindow &temp)
    {
        out<<(CWindow)temp<<endl;
        for(int i=0;i<temp.m_Button.size();i++)
        {
            out<<"����"<<i<<"��Ϣ:"<<temp.m_Button[i]<<endl;
        }
        out<<"��������:"<<temp.m_txt;
        return out;
    }
};
int main()
{
CAppWindow app1;
cout << "====app1 Ӧ����Ϣ======\n";
cout << app1 << "\n" << endl;
cout << "====app1ǰ����===\n";
++app1;
cout << app1 << "\n\n";
cout << "===app1�޸İ������ơ����Լ�===\n";
app1.setButtonName(2,"Cancel");
app1.setButtonName(1,"OK");
cout << app1-- << "\n\n";
cout << "===app1���ڷŴ��޸��ı����Լ���===\n";
app1.zoom(200);
app1[2] = 'A';
app1[100] = 'S';
cout << app1 << "\n\n";
system("pause");
return 0;
}
