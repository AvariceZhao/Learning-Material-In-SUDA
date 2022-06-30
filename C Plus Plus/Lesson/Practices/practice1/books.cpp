#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class CGoods
{
string m_name; //商品名称
double m_price; //商品价格
public:
CGoods(string name,double price) //构造函数
{
m_name=name;
m_price=price;
}
string getName() const //获取商品名称
{
return m_name;
}
double getPrice() const //获取商品价格
{
return m_price;
}
void setPrice(double price) //设置商品价格
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
        out<<"书名:"<<temp.getName()<<endl
        <<"价格:"<<temp.getPrice()<<endl
        <<"作者:"<<temp.m_writer<<endl
        <<"页数:"<<temp.m_pages<<endl
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
 
vector<CBook> myVect; //创建向量
readData("d:\\books.txt",myVect); //从文件中读取数据到向量

showData(myVect); //显示读取到的数据
  
vector<CBook> myVectNew; //创建向量
processData(myVectNew,myVect); //对页码大于200页的书籍执行前置--，

//同时把该对象插入到myVectNew中
//其余书籍执行后置--，
//同时把该对象插入到myVectNew中
showData(myVectNew);

outputData(myVectNew); //输出myVectNew中所有价格低于10元
//的书籍名称，一行一个
 system("pause");
 return 0;
}
