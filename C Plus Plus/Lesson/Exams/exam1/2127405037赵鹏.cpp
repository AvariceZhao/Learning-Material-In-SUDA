//赵鹏 2127405037 
//Created By Vscode,Encoding=UTF-8
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<string>
#include<fstream>
using namespace  std;
struct info
{
	string	sfzh;//身份证号
	int		ct;  //Ct值
};
//1.	编写函数readInfo，读取出文件中的所有数据并存在struct info类型的infos向量中；
bool readInfo(const char pathFile[],vector<struct info> &infos)//声明函数
{
    ifstream iFile;
    iFile.open(pathFile);//打开文件

    if(iFile.fail())//如果打开失败则返回false
        return false;

    string SFZH;
    int Ct0;
    
    while(iFile>>SFZH>>Ct0)//按行读入身份证号和ct值
    {
        info temp;//定义临时存储结构体

        temp.sfzh=SFZH;//赋值
        temp.ct=Ct0;
        
        infos.push_back(temp);//存储倒infos向量中
    }
    iFile.close();//关闭文件，防止意外错误的发生
    return true;
}

//2.	编写函数showInfo，显示第1步所生成向量的前5条数据，（如果不足5条则全部显示）显示格式如下：身份证号（占20列，左对齐）	Ct值(占5列，右对齐)

void showInfo(vector<struct info> &infos,int num=5)//设置默认参数为5
{
    for(int i=0;i<min(num,(int)infos.size());i++)//如果不足5则显示全部
    {
        cout<<setw(20)<<left<<infos[i].sfzh;//输出身份证号码，占20行，左对齐
        cout<<setw(5)<<right<<infos[i].ct;//输出ct值，占5行，右对齐
        cout<<endl; //换行
    }

}
//3.	编写函数delInfo，删除infos向量中身份证号码长度不合法的数据（中华人民共和国第二代身份证号码应该为18位）；
int delInfo(vector<struct info> &infos)//声明函数
{
	int delCount=0;//对删除的个数进行计数

	vector<struct info>::iterator p=infos.begin();//定义迭代器用于遍历

	while(p!=infos.end())//当没有结束时
	{
		if((*p).sfzh.size()!=18)//判断迭代器所指的数据的sfzh的长度是否合法
		{
			p=infos.erase(p);//不合法则删除
			delCount++;//对删除进行计数
		}
		else//如果合法
		p++;	//不执行删除操作，迭代器向后移
	}
	return delCount; 
}
//4.	编写函数SortInfo，按照Ct值从小到大对数据进行排序，当Ct相同时按照身份证号的ASCII码从小到大排序；
bool cmp(info infoA,info infoB)//自定义sort的比较函数
{
	if(infoA.ct!=infoB.ct)//如果ct值不等
		return infoA.ct<infoB.ct;//按照ct值从小到大进行排序
	else//如果相等
		return infoA.sfzh<infoB.sfzh;//按照身份证号码的ASCII码从小到大进行排序
}
void sortInfo(vector<struct info> &infos)
{
	sort(infos.begin(),infos.end(),cmp);//调用algorithm库的sort函数进行排序，传出sort函数作为参数自定义排序规则
}

//5.	编写函数groupInfo统计出阳性、灰区和阴性的人数并用向量返回；
vector<int> groupInfo(vector<struct info> &infos)//声明函数
{	
    vector<int> ans;//定义一个向量存储结果，用于函数的返回
	int nagativeNum=0,positiveNum=0,greyNum=0;//定义阴性,阳性，灰区人数
	for(int i=0;i<infos.size();i++)
	{
		if(infos[i].ct>=40||infos[i].ct==0)//如果是阴性
			nagativeNum++;//阴性个数加一
		else if (infos[i].ct<37)//如果是阳性
			positiveNum++;//阳性个数加一
		else if (infos[i].ct>=37&&infos[i].ct<40)//如果是灰区
			greyNum++;//灰区个数加一
	}
    //将结果存储到ans向量中
	ans.push_back(positiveNum);
	ans.push_back(greyNum);
	ans.push_back(nagativeNum);

	return ans;//返回结果
}

//6.编写函数writeInfo将排序后的Ct值在灰区的人员信息全部输出到D盘根文件夹下的文本文件out.txt中。
//输出时每行一条数据，先输出身份证号再输出Ct值，二者之间用英文逗号分开；
bool writeInfo(const char outPath[],vector<struct info> &infos)//声明函数
{
	ofstream ofile;
	ofile.open(outPath);//打开输出文件

	if(ofile.fail())//如果打开失败则返回false
		return false;

	for(int i=0;i<infos.size();i++)//遍历向量列表
	{
		if(infos[i].ct>=37&&infos[i].ct<40)//如果是灰区
		{
			ofile<<infos[i].sfzh<<","<<infos[i].ct<<endl;//先输出身份证号再输出ct值，用英文逗号分隔
		}
	}
	ofile.close();//关闭文件，防止意外错误

	return true;//写入文件成功，返回true
}

/*
7.编写函数找出身份证号码校验位不正确的人员，并把身份证号码存储在string类型的向量res中。中国人民共和国第二代居民身份证号码是18位编码，第18位是校验码。校验规则如下：
将身份证号码前面的17位数分别乘以不同的系数。从第1位到第17位的系数分别为：7、9、10、5、8、4、2、1、6、3、7、9、10、5、8、4、2
将这17位数字和系数分别相乘的结果相加
用上面累加结果除以11，取余数。
余数只可能有0、1、2、3、4、5、6、7、8、9、10这11个数字。其分别对应的最后一位身份证的号码为1、0、X、9、8、7、6、5、4、3、2。
*/
vector <string> findInvalidSfzh(vector<struct info> &infos)//声明函数
{	
    vector <string> res;
	int mul[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//利用数组存储前17位数字乘的系数
	int num[11]={1,0,'X',9,8,7,6,5,4,3,2};//存储最终取模值

	for(int i=0;i<infos.size();i++)//遍历向量的每一个身份证号
	{
		int temp=0;//用于存储乘积
		for(int j=0;j<17;j++)
			temp+=mul[j]*(infos[i].sfzh[j]-'0');//累加乘积
		
		temp%=11;//对11取模

		if(temp==2&&infos[i].sfzh[17]!='X')//当余数是2时特判身份证号的最后一位是否是X
			res.push_back(infos[i].sfzh);
		else
		{
			if(num[temp]!=infos[i].sfzh[17]-'0')//判断当前余数对应的校验位与身份证号最后一位是否相等
				res.push_back(infos[i].sfzh);//如果不等则存储到res中
		}
	}
	return res;
}
//8.	编写一个重载函数showInfo显示res的全部结果到屏幕，一行一个身份证号，如果res为空，则显示“身份证号全部正确”。
void showInfo(vector <string> &res)//声明showInfo的重载函数
{
	if(res.empty())//如果为空
	{
	
		cout<<"身份证号全部正确"<<endl;//输出全部正确
	}
	else//否则
	{
		for(int i=0;i<res.size();i++)//每行输出一个不合法的身份证号
			cout<<res[i]<<endl;
				
	}	
}
int main()
{
	vector<struct info> infos;
	if (readInfo("d:\\input.txt", infos) == false)
	{
		cout << "打开文件失败，请确认文件路径" << endl;
		return 0;
	}
	cout << "合计有"<<infos.size()<<"条数据。";
	cout << "前5条数据为：" << endl;
	showInfo(infos);
	int count = delInfo(infos);
	cout << "删除了身份证不合法的" << count << "条，剩余" << infos.size() << "条" << endl;
	sortInfo(infos);
	cout << "排序后数据为：" << endl;
	showInfo(infos,infos.size());
	vector<int> counts = groupInfo(infos);
	cout << "其中陽性：" << counts[0] << "人"<< endl;
	cout << "其中灰区：" << counts[1] << "人" << endl;
	cout << "其中阴性：" << counts[2] << "人" << endl;
	if (writeInfo("d:\\out.txt", infos) == true)
	{
		cout << "写文件成功"<<endl;
	}
	else
	{
		cout << "打开文件失败"<<endl;
	}
	vector <string> res = findInvalidSfzh(infos);
	cout << "身份证号错误检查结果如下：" << endl;
	showInfo(res);
	return 0;
}

