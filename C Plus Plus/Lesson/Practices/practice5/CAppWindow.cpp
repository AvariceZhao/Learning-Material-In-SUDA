#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class CButton
{
private:
int m_width; // Button的宽度，范围:[50,500],单位：像素
int m_high; // Button的高度，范围:[25,250],单位：像素
string m_name; // Button的名字
public:
CButton(int width= 100, int high= 50, const string & name= "NULL"); // 带默认参数值的构造函数
string getName()const; //获取Button名字的常成员函数
void setName(const string&); // 设置Button名字的成员函数
friend ostream& operator<<(ostream &out,const CButton &temp)
{
    out<<"按键信息(宽、高、名称)：";
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
int m_width; // 窗口的宽，非负整数，单位：像素
int m_hight; // 窗口的高，非负整数，单位：像素
public:
CWindow(int width= 500, int high= 400):m_width(width),m_hight(high){};
void zoom(int); // 缩放窗口
friend ostream & operator<<(ostream &out,const CWindow &temp)
{
    out<<"窗口信息(宽、高)：";
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
        m_Button.push_back({100,50,"最小化"});
        m_Button.push_back({100,50,"关闭"});
        for(int i=0;i<buttonNum-2;i++)
        m_Button.push_back({});       
    };
    CAppWindow  & operator++()
    {
        m_Button.push_back({120,60,"最大化"});
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
            cout<<"不进行按键删除操作";
        }
        return t;
    }
    char & operator[](int index)
    {
        int len=m_txt.size();
        if(index<0||index>=len)
        {
            cout<<"索引越界"<<endl;
            return m_txt[0];
        }
        else 
            return m_txt[index];
    }
    void setButtonName(int x,string name)
    {
        if(x<2)
        {
            cout<<"不允许修改名字"<<endl;
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
            out<<"按键"<<i<<"信息:"<<temp.m_Button[i]<<endl;
        }
        out<<"窗口内容:"<<temp.m_txt;
        return out;
    }
};
int main()
{
CAppWindow app1;
cout << "====app1 应用信息======\n";
cout << app1 << "\n" << endl;
cout << "====app1前自增===\n";
++app1;
cout << app1 << "\n\n";
cout << "===app1修改按键名称、后自减===\n";
app1.setButtonName(2,"Cancel");
app1.setButtonName(1,"OK");
cout << app1-- << "\n\n";
cout << "===app1窗口放大、修改文本、自减后===\n";
app1.zoom(200);
app1[2] = 'A';
app1[100] = 'S';
cout << app1 << "\n\n";
system("pause");
return 0;
}
