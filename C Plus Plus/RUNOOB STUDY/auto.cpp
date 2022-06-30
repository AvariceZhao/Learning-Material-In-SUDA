#include<bits/stdc++.h>
using namespace std;
int count;
extern void write_extern();
int main()
{
	register int miles;//register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小
	static int count=10;//static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
	extern int a;//extern提供全局变量引用，对所有程序文件都用 ，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。可以这么理解，extern 是用来在另一个文件中声明一个全局变量或函数。 
	write_extern();
	return 0;
}
