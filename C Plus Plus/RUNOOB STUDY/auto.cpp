#include<bits/stdc++.h>
using namespace std;
int count;
extern void write_extern();
int main()
{
	register int miles;//register �洢�����ڶ���洢�ڼĴ����ж����� RAM �еľֲ�����������ζ�ű��������ߴ���ڼĴ����Ĵ�С
	static int count=10;//static �洢��ָʾ�������ڳ�������������ڱ��־ֲ������Ĵ��ڣ�������Ҫ��ÿ����������뿪������ʱ���д��������١���ˣ�ʹ�� static ���ξֲ����������ں�������֮�䱣�־ֲ�������ֵ��
	extern int a;//extern�ṩȫ�ֱ������ã������г����ļ����� �������������ļ���ʹ�� extern ���õ��Ѷ���ı������������á�������ô��⣬extern ����������һ���ļ�������һ��ȫ�ֱ��������� 
	write_extern();
	return 0;
}
