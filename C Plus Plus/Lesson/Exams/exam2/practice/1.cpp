#include<iostream>
using namespace std;
class CBubbleTea{
    private:
    static int m_totalCount;
    int m_No;
    int m_type;//[1,5]
    int m_vol;//(500.750.1000)

    public:
    CBubbleTea(int type=1,int vol=500)//���캯����Ĭ��ֵ
    {   
        if((type>=1&&type<=5)&&(vol==500||vol==750||vol==1000))//����Ϸ�
        {
        m_No=m_totalCount+1;
        m_totalCount++;
        m_type=type;m_vol=vol;
        }
        else//���Ϸ�
        {
        m_type=0;m_vol=0;
        }
        
    }
    CBubbleTea(const CBubbleTea &temp)//�������캯��
    {
        if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))//�Ϸ�
        {
            m_No=m_totalCount+1;
            m_totalCount++;
            m_type=temp.m_type;
            m_vol=temp.m_vol;
        }
        else//���Ϸ�
        {
              m_type=0;  m_vol=0;
        }
    }
    static int get_totalCount()//�����ܱ���
    {
        return m_totalCount;
    }
    int get_No()const//���ر��
    {
        return m_No;
    }
    int get_Type()const//��������
    {
        return m_type;
    }
    int get_Vol()const//��������
    {
        return m_vol;
    }
    friend  CBubbleTea& operator++ (CBubbleTea &temp)//ǰ���������������
    {
        if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))//����Ϸ�
        {
            if(temp.m_vol!=1000)//��������������
            {
                temp.m_vol+=250;
            }
        }
    }
    	void operator=(CBubbleTea &temp)//��ֵ���������
	{
		  if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))//����Ϸ�
        {
            m_No=m_totalCount+1;
            m_totalCount++;
            m_type=temp.m_type;
            m_vol=temp.m_vol;
        }
        else//���Ϸ�
        {
              m_type=0;  m_vol=0;
        }
	}

    friend ostream&operator<<(ostream &out, CBubbleTea&temp)//�����������
    {     
    if((temp.m_type>=1&&temp.m_type<=5)&&(temp.m_vol==500||temp.m_vol==750||temp.m_vol==1000))
    {
        cout<<"**********"<<endl;
        cout<<"�̲���:"<<temp.m_No<<endl;//����̲���

        cout<<"�̲�����:";//����̲����ͼ�����
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
        
        cout<<"�̲�����:"<<temp.m_vol<<"����"<<endl;//����̲�����
        cout<<"**********"<<endl;
    }
    else//������ݲ��Ϸ�
    {   cout<<"**********"<<endl;
        cout<<"��Ч����"<<endl;
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
	cout << "�ϼ�������:"<<CBubbleTea::get_totalCount() <<"���̲�"<< endl;
	return 0;
}
