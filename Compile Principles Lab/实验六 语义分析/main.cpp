//2127405037 zhaopeng
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include"LexerNFA.hpp"
#include"Parse.hpp"
map<string, vector<string>> tree;
using namespace std;
string tree_root="";
const char* file="test.txt";
const char* out = "out.txt";
int main()
{
	LexerNFA lexer(file, out);
	int t = lexer.run();
	if (t == -1)
	{
		std::cout << "词法分析错误\n";
	}


	else
	{

		int t=TESTparse();
		if (t != 0)
			std::cout << "汇编代码生成失败\n";
		else
		
			std::cout << "汇编代码生成成功\n";
	}
		return 0;
}



/*
16
r9 r7
r9 r8
r7 r5
r7 r6
r8 b
r5 r4
r5 *
r6 a
r4 (
r4 r3
r4 )
r3 r1
r3 |
r3 r2
r1 a
r2 b
*/





















/*
* 




26
r13 r3
r3 r1
r1 1
r3 r2
r2 0
r13 |
r13 r12
r12 r14
r14 r9
r9 (
r9 r8
r8 r4
r4 0
r8 |
r8 r7
r7 r5
r5 1
r7 r6
r6 1
r9 )
r14 r10
r10 r15
r15 0
r10 *
r12 r11
r11 1












/*
* 
19
r8 r7
r8 r11
r7 r6
r7 r10
r6 r5
r6 r9
r5 r4
r5 *
r4 (
r4 r3
r4 )
r3 r1
r3 |
r3 r2
r1 a
r2 b
r9 a
r10 b
r11 b
*/