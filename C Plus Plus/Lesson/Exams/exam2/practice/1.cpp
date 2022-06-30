#include<iostream>
using namespace std;
class CBubbleTea{
    private:
    static int m_totalCount;
    int m_No;
    int m_type;//[1,5]
    int m_vol;//(500.750.1000)

    public:
    CBubbleTea(int type=1,int vol=500)//构造函数及默认值
    {   
        if((type>=1&&type<=5)&&(vol==500||vol==750||vol==1000))//如果合法
        {
        m_No=m_totalCount+1;
        m_totalCount++;
        m_type=type;m_vol=vol;
        }
        else//不合法
        {
        m_type=0;m_vol=0;
        }
        
    }
    CBubbleTea(const CBubbleTea &temp)//拷贝构造函数
    {
        if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))//合法
        {
            m_No=m_totalCount+1;
            m_totalCount++;
            m_type=temp.m_type;
            m_vol=temp.m_vol;
        }
        else//不合法
        {
              m_type=0;  m_vol=0;
        }
    }
    static int get_totalCount()//返回总杯数
    {
        return m_totalCount;
    }
    int get_No()const//返回编号
    {
        return m_No;
    }
    int get_Type()const//返回种类
    {
        return m_type;
    }
    int get_Vol()const//返回容量
    {
        return m_vol;
    }
    friend  CBubbleTea& operator++ (CBubbleTea &temp)//前置自增运算符重载
    {
        if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))//如果合法
        {
            if(temp.m_vol!=1000)//如果不是最大容量
            {
                temp.m_vol+=250;
            }
        }
    }
    	void operator=(CBubbleTea &temp)//赋值运算符重载
	{
		  if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))//如果合法
        {
            m_No=m_totalCount+1;
            m_totalCount++;
            m_type=temp.m_type;
            m_vol=temp.m_vol;
        }
        else//不合法
        {
              m_type=0;  m_vol=0;
        }
	}

    friend ostream&operator<<(ostream &out, CBubbleTea&temp)//流运算符重载
    {     
    if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))
    {
        cout<<"**********"<<endl;
        cout<<"奶茶编号:"<<temp.m_No<<endl;//输出奶茶编号

        cout<<"奶茶类型:";//输出奶茶类型及名称
        if(temp.m_type==1)
            cout<<"Coconut milk tea"<<endl;
        else if(temp.m_type==2)
            cout<<"Fruit tea"<<endl;
        else if(temp.m_type==3)
            cout<<"Green tea"<<endl;
        else if(temp.m_type==4)
            cout<<"Black tea"<<endl;
        else if(temp.m_type==5)
            cout<<"Coffee"<<endl;
        
        cout<<"奶茶容量:"<<temp.m_vol<<"毫升"<<endl;//输出奶茶容量
        cout<<"**********"<<endl;
    }
    else//如果数据不合法
    {   cout<<"**********"<<endl;
        cout<<"无效数据"<<endl;
        cout<<"**********"<<endl;
    }
    }
    friend int main();
};
int CBubbleTea::m_totalCount=0;
int main()
{
	CBubbleTea tea1(2, 500);
	cout << tea1;
	CBubbleTea tea2(tea1);
	cout << tea2;
	CBubbleTea tea3(2, 5000);
	cout << tea3;
	tea3 = tea2;
	cout << tea3;
	cout << ++tea3;
	cout << "合计生产了:"<<CBubbleTea::get_totalCount() <<"杯奶茶"<< endl;
	return 0;
}
