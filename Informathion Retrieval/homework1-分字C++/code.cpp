#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<string.h>
#include<windows.h>
using namespace std;
string temp;int n,i;

int getBytes(char c)//获取构成下一个字符的字节数，即第一个字节二进制下开头连续1的个数
{   int cnt=0;
    int x=c+256;//将强制转换后的负数转为正数
	while(x)//从末位开始遍历每一位
    {	
        if((x&1)==0)//如果出现了非0的情况
        cnt=0;//出现了不连续的1,重置计数器
        else
        cnt++;//计数器+1
        x>>=1;//右移遍历下一位
    }
    return cnt;
}
int main()
{   


	ifstream myfile("./Sentence.txt");//打开数据文件
	ofstream outfile("./out.txt");//打开输出文件

	
	outfile<<temp;
	if(!myfile.is_open())//打开失败
	{
		cout<<"failed to open the file"<<endl;
        return 0;
	}
	while(getline(myfile,temp))//逐行处理
	{	
		i=-1;
        while(temp[++i]!=0)//没有遍历到该行末尾
        {
            int l=getBytes(temp[i]);//获取构成当前字符的字节数
            if(l==1)//去除半角字符
                continue;
            if(l==0)//特殊字符直接输出
            {
                outfile<<temp[i];
                continue;
            }
            
            char c[10];//临时存储字符
            int cnt=0;
            
            memset(c,0,sizeof c);//重置
            
            for(int j=i;j<i+l;j++)//将当前指针开始的后几位存储起来，构成一个字
            {
            c[cnt]=temp[j];
            cnt++;
            } 

             for(int j = 0; j < cnt; j ++){//输出当前字符
                outfile << c[j];
            }
            
            if(temp[i + 1] == 0 )
            outfile<<("");
            else
            outfile<<("/");//输出一个“/”
         
        }
        outfile << endl;
           
       

    }

    
	myfile.close();//关闭文件
	outfile.close();
  	cout<<"Completed!";
      system("pause");
	return 0;
	 
}

