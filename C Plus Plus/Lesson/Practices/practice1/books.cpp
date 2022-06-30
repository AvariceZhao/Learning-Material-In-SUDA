#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class CGoods
{
string m_name; //��Ʒ����
double m_price; //��Ʒ�۸�
public:
CGoods(string name,double price) //���캯��
{
m_name=name;
m_price=price;
}
string getName() const //��ȡ��Ʒ����
{
return m_name;
}
double getPrice() const //��ȡ��Ʒ�۸�
{
return m_price;
}
void setPrice(double price) //������Ʒ�۸�
{
m_price=price;
}
};

class CBook:public CGoods
{
    private:
        string m_writer;
        int m_pages;
    public:
    CBook(string name,double price,string writer,int pages):CGoods(name,price)
    {
        m_writer=writer;
        m_pages=pages;
    }
    CBook & operator --()
    {
        double t=getPrice();
        if(t>10)
        {
            setPrice(t-1);
        }      
        return *this; 
    }
    CBook operator--(int)
    {
        auto temp=*this;
        double t=getPrice();
        if(t>10)
        {
            setPrice(t-1);
        }
        return temp;      
    }
    friend ostream & operator<<(ostream &out,const CBook &temp)
    {
        out<<"����:"<<temp.getName()<<endl
        <<"�۸�:"<<temp.getPrice()<<endl
        <<"����:"<<temp.m_writer<<endl
        <<"ҳ��:"<<temp.m_pages<<endl
        <<"============================================"<<endl;
        return out;
    }
    int getPages()const
    {
        return m_pages;
    }


};
void readData(const char path[],vector<CBook> &myVect)
{
    string name,writer;
    double price;
    int pages;
    ifstream iFile(path);
    while(iFile>>name>>price>>writer>>pages)
    {
        myVect.push_back({name,price,writer,pages});
    }
    iFile.close();
}
void showData(const vector<CBook> &myVect)
{
    for(auto book:myVect)
    cout<<book;
}
void processData(vector<CBook> &myVectNew, vector<CBook> &myVect)
{
    for(auto &book:myVect)
    {
        if(book.getPages()>200)
        myVectNew.push_back(--book);
        else
        myVectNew.push_back(book--);
        
        
    }
}
void outputData(vector<CBook> &myVectNew)
{
    for(auto book:myVectNew)
    {
        if(book.getPrice()<10)
        cout<<book.getName()<<endl;
    }
}
int main()
{
 
vector<CBook> myVect; //��������
readData("d:\\books.txt",myVect); //���ļ��ж�ȡ���ݵ�����

showData(myVect); //��ʾ��ȡ��������
  
vector<CBook> myVectNew; //��������
processData(myVectNew,myVect); //��ҳ�����200ҳ���鼮ִ��ǰ��--��

//ͬʱ�Ѹö�����뵽myVectNew��
//�����鼮ִ�к���--��
//ͬʱ�Ѹö�����뵽myVectNew��
showData(myVectNew);

outputData(myVectNew); //���myVectNew�����м۸����10Ԫ
//���鼮���ƣ�һ��һ��
 system("pause");
 return 0;
}
