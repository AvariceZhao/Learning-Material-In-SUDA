#include<iostream>
#include<cstdio>
#include"sequenceList.hpp"
#include"linkedList.hpp"
#include"circularLinkedList.hpp"
#include"doubleLinkedList.hpp"
#include"doubleCircularLinkedList.hpp"
#include"BigNum.hpp"
using namespace std;
int main()
{
   /*
    int data[10] = { 1,2,3,4,5,6,7,8,9 ,10};
    cout << "data[10]={1,2,3,4,5,6,7,8,9}" << endl;
    cout << endl;

    cout << "线性表测试" << endl;
    SequenceList<int>A(data,10);
    cout << "从data数组初始化完成" << endl;
    cout << "当前表为" << endl;
    A.Print();
    cout << "向第五个位置插入20" << endl;
    A.Insert(5, 20);
    cout << "当前表为" << endl;
    A.Print();
    cout << "删除第五个位置的20" << endl;
    A.Delete(5);
    cout << "当前表为" << endl;
    A.Print();
    cout << "按值查找9" << endl;
    cout << A.Find(9) << endl;
    cout << "按位查找3" << endl;
    cout << A.Get(3) << endl;
    cout << "获取表长" << endl;
    cout << A.Length() << endl;
    cout << "销毁表" << endl;
    A.Clear();
    cout << "当前表为" << endl;
    A.Print();
    cout << "判断表空" << endl;
    cout << A.Empty() << endl;
    cout << "---------------------------------------------" << endl;


    cout << "单链表表测试" << endl;
    linkedList<int>B(data, 10);
    cout << "从data数组初始化完成" << endl;
    cout << "当前表为" << endl;
    B.Print();
    cout << "向第五个位置插入20" << endl;
    B.Insert(5, 20);
    cout << "当前表为" << endl;
    B.Print();
    cout << "删除第五个位置的20" << endl;
    B.Delete(5);
    cout << "当前表为" << endl;
    B.Print();
    cout << "按值查找9" << endl;
    cout << B.Find(9) << endl;
    cout << "按位查找3" << endl;
    cout << B.Get(3) << endl;
    cout << "获取表长" << endl;
    cout << B.Length() << endl;
    cout << "销毁表" << endl;
    B.Clear();
    cout << "当前表为" << endl;
    B.Print();
    cout << "判断表空" << endl;
    cout << B.Empty() << endl;
    cout << "---------------------------------------------" << endl;

    cout << "单循环表测试" << endl;
    circularLinkedList<int>C(data, 10);
    cout << "从data数组初始化完成" << endl;
    cout << "当前表为" << endl;
    C.Print();
    cout << "向第五个位置插入20" << endl;
    C.Insert(5, 20);
    cout << "当前表为" << endl;
    C.Print();
    cout << "删除第五个位置的20" << endl;
    C.Delete(5);
    cout << "当前表为" << endl;
    C.Print();
    cout << "按值查找9" << endl;
    cout << C.Find(9) << endl;
    cout << "按位查找3" << endl;
    cout << C.Get(3) << endl;
    cout << "获取表长" << endl;
    cout << C.Length() << endl;
    cout << "销毁表" << endl;
    C.Clear();
    cout << "当前表为" << endl;
    C.Print();
    cout << "判断表空" << endl;
    cout << C.Empty() << endl;
    cout << "---------------------------------------------" << endl;


    cout << "双链表测试" << endl;
    doubleLinkedList<int>D(data, 10);
    cout << "从data数组初始化完成" << endl;
    cout << "当前表为" << endl;
    D.Print();
    cout << "向第五个位置插入20" << endl;
    D.Insert(5, 20);
    cout << "当前表为" << endl;
    D.Print();
    cout << "删除第五个位置的20" << endl;
    D.Delete(5);
    cout << "当前表为" << endl;
    D.Print();
    cout << "按值查找9" << endl;
    cout << D.Find(9) << endl;
    cout << "按位查找3" << endl;
    cout << D.Get(3) << endl;
    cout << "获取表长" << endl;
    cout << D.Length() << endl;
    cout << "销毁表" << endl;
    D.Clear();
    cout << "当前表为" << endl;
    D.Print();
    cout << "判断表空" << endl;
    cout << D.Empty() << endl;
    cout << "---------------------------------------------" << endl;

    cout << "双循环表测试" << endl;
    doubleCircularLinkedList<int>E(data, 10);
    cout << "从data数组初始化完成" << endl;
    cout << "当前表为" << endl;
    E.Print();
    cout << "向第五个位置插入20" << endl;
    E.Insert(5, 20);
    cout << "当前表为" << endl;
    E.Print();
    cout << "删除第五个位置的20" << endl;
    E.Delete(5);
    cout << "当前表为" << endl;
    E.Print();
    cout << "按值查找9" << endl;
    cout << E.Find(9) << endl;
    cout << "按位查找3" << endl;
    cout << E.Get(3) << endl;
    cout << "获取表长" << endl;
    cout << E.Length() << endl;
    cout << "销毁表" << endl;
    E.Clear();
    cout << "当前表为" << endl;
    E.Print();
    cout << "判断表空" << endl;
    cout << A.Empty() << endl;
    cout << "---------------------------------------------" << endl;
    */
while (true)
{
    cout << "输入两个长整数,将自动输出两个数的四种运算结果" << endl;
    string A, B;
    cin >> A >> B;
    BigNum NUM1(A), NUM2(B);
    BigNum C;
    C = NUM1 + NUM2;
    cout << A << "+" << B << "=";
    C.print();
    C = NUM1 - NUM2;
    cout << A << "-" << B << "=";
    C.print();

    C = NUM2 - NUM1;
    cout << B << "-" << A << "=";
    C.print();
    cout << A << "*" << B << "=";
    C = NUM1 * NUM2;
    C.print();
    cout << "--------------------------------------------" << endl;
}
    return 0;
}

