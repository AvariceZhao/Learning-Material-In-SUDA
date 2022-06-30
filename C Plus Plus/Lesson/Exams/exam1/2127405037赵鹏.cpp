//���� 2127405037 
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
	string	sfzh;//���֤��
	int		ct;  //Ctֵ
};
//1.	��д����readInfo����ȡ���ļ��е��������ݲ�����struct info���͵�infos�����У�
bool readInfo(const char pathFile[],vector<struct info> &infos)//��������
{
    ifstream iFile;
    iFile.open(pathFile);//���ļ�

    if(iFile.fail())//�����ʧ���򷵻�false
        return false;

    string SFZH;
    int Ct0;
    
    while(iFile>>SFZH>>Ct0)//���ж������֤�ź�ctֵ
    {
        info temp;//������ʱ�洢�ṹ��

        temp.sfzh=SFZH;//��ֵ
        temp.ct=Ct0;
        
        infos.push_back(temp);//�洢��infos������
    }
    iFile.close();//�ر��ļ�����ֹ�������ķ���
    return true;
}

//2.	��д����showInfo����ʾ��1��������������ǰ5�����ݣ����������5����ȫ����ʾ����ʾ��ʽ���£����֤�ţ�ռ20�У�����룩	Ctֵ(ռ5�У��Ҷ���)

void showInfo(vector<struct info> &infos,int num=5)//����Ĭ�ϲ���Ϊ5
{
    for(int i=0;i<min(num,(int)infos.size());i++)//�������5����ʾȫ��
    {
        cout<<setw(20)<<left<<infos[i].sfzh;//������֤���룬ռ20�У������
        cout<<setw(5)<<right<<infos[i].ct;//���ctֵ��ռ5�У��Ҷ���
        cout<<endl; //����
    }

}
//3.	��д����delInfo��ɾ��infos���������֤���볤�Ȳ��Ϸ������ݣ��л����񹲺͹��ڶ������֤����Ӧ��Ϊ18λ����
int delInfo(vector<struct info> &infos)//��������
{
	int delCount=0;//��ɾ���ĸ������м���

	vector<struct info>::iterator p=infos.begin();//������������ڱ���

	while(p!=infos.end())//��û�н���ʱ
	{
		if((*p).sfzh.size()!=18)//�жϵ�������ָ�����ݵ�sfzh�ĳ����Ƿ�Ϸ�
		{
			p=infos.erase(p);//���Ϸ���ɾ��
			delCount++;//��ɾ�����м���
		}
		else//����Ϸ�
		p++;	//��ִ��ɾ�������������������
	}
	return delCount; 
}
//4.	��д����SortInfo������Ctֵ��С��������ݽ������򣬵�Ct��ͬʱ�������֤�ŵ�ASCII���С��������
bool cmp(info infoA,info infoB)//�Զ���sort�ıȽϺ���
{
	if(infoA.ct!=infoB.ct)//���ctֵ����
		return infoA.ct<infoB.ct;//����ctֵ��С�����������
	else//������
		return infoA.sfzh<infoB.sfzh;//�������֤�����ASCII���С�����������
}
void sortInfo(vector<struct info> &infos)
{
	sort(infos.begin(),infos.end(),cmp);//����algorithm���sort�����������򣬴���sort������Ϊ�����Զ����������
}

//5.	��д����groupInfoͳ�Ƴ����ԡ����������Ե����������������أ�
vector<int> groupInfo(vector<struct info> &infos)//��������
{	
    vector<int> ans;//����һ�������洢��������ں����ķ���
	int nagativeNum=0,positiveNum=0,greyNum=0;//��������,���ԣ���������
	for(int i=0;i<infos.size();i++)
	{
		if(infos[i].ct>=40||infos[i].ct==0)//���������
			nagativeNum++;//���Ը�����һ
		else if (infos[i].ct<37)//���������
			positiveNum++;//���Ը�����һ
		else if (infos[i].ct>=37&&infos[i].ct<40)//����ǻ���
			greyNum++;//����������һ
	}
    //������洢��ans������
	ans.push_back(positiveNum);
	ans.push_back(greyNum);
	ans.push_back(nagativeNum);

	return ans;//���ؽ��
}

//6.��д����writeInfo��������Ctֵ�ڻ�������Ա��Ϣȫ�������D�̸��ļ����µ��ı��ļ�out.txt�С�
//���ʱÿ��һ�����ݣ���������֤�������Ctֵ������֮����Ӣ�Ķ��ŷֿ���
bool writeInfo(const char outPath[],vector<struct info> &infos)//��������
{
	ofstream ofile;
	ofile.open(outPath);//������ļ�

	if(ofile.fail())//�����ʧ���򷵻�false
		return false;

	for(int i=0;i<infos.size();i++)//���������б�
	{
		if(infos[i].ct>=37&&infos[i].ct<40)//����ǻ���
		{
			ofile<<infos[i].sfzh<<","<<infos[i].ct<<endl;//��������֤�������ctֵ����Ӣ�Ķ��ŷָ�
		}
	}
	ofile.close();//�ر��ļ�����ֹ�������

	return true;//д���ļ��ɹ�������true
}

/*
7.��д�����ҳ����֤����У��λ����ȷ����Ա���������֤����洢��string���͵�����res�С��й����񹲺͹��ڶ����������֤������18λ���룬��18λ��У���롣У��������£�
�����֤����ǰ���17λ���ֱ���Բ�ͬ��ϵ�����ӵ�1λ����17λ��ϵ���ֱ�Ϊ��7��9��10��5��8��4��2��1��6��3��7��9��10��5��8��4��2
����17λ���ֺ�ϵ���ֱ���˵Ľ�����
�������ۼӽ������11��ȡ������
����ֻ������0��1��2��3��4��5��6��7��8��9��10��11�����֡���ֱ��Ӧ�����һλ���֤�ĺ���Ϊ1��0��X��9��8��7��6��5��4��3��2��
*/
vector <string> findInvalidSfzh(vector<struct info> &infos)//��������
{	
    vector <string> res;
	int mul[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//��������洢ǰ17λ���ֳ˵�ϵ��
	int num[11]={1,0,'X',9,8,7,6,5,4,3,2};//�洢����ȡģֵ

	for(int i=0;i<infos.size();i++)//����������ÿһ�����֤��
	{
		int temp=0;//���ڴ洢�˻�
		for(int j=0;j<17;j++)
			temp+=mul[j]*(infos[i].sfzh[j]-'0');//�ۼӳ˻�
		
		temp%=11;//��11ȡģ

		if(temp==2&&infos[i].sfzh[17]!='X')//��������2ʱ�������֤�ŵ����һλ�Ƿ���X
			res.push_back(infos[i].sfzh);
		else
		{
			if(num[temp]!=infos[i].sfzh[17]-'0')//�жϵ�ǰ������Ӧ��У��λ�����֤�����һλ�Ƿ����
				res.push_back(infos[i].sfzh);//���������洢��res��
		}
	}
	return res;
}
//8.	��дһ�����غ���showInfo��ʾres��ȫ���������Ļ��һ��һ�����֤�ţ����resΪ�գ�����ʾ�����֤��ȫ����ȷ����
void showInfo(vector <string> &res)//����showInfo�����غ���
{
	if(res.empty())//���Ϊ��
	{
	
		cout<<"���֤��ȫ����ȷ"<<endl;//���ȫ����ȷ
	}
	else//����
	{
		for(int i=0;i<res.size();i++)//ÿ�����һ�����Ϸ������֤��
			cout<<res[i]<<endl;
				
	}	
}
int main()
{
	vector<struct info> infos;
	if (readInfo("d:\\input.txt", infos) == false)
	{
		cout << "���ļ�ʧ�ܣ���ȷ���ļ�·��" << endl;
		return 0;
	}
	cout << "�ϼ���"<<infos.size()<<"�����ݡ�";
	cout << "ǰ5������Ϊ��" << endl;
	showInfo(infos);
	int count = delInfo(infos);
	cout << "ɾ�������֤���Ϸ���" << count << "����ʣ��" << infos.size() << "��" << endl;
	sortInfo(infos);
	cout << "���������Ϊ��" << endl;
	showInfo(infos,infos.size());
	vector<int> counts = groupInfo(infos);
	cout << "������ԣ�" << counts[0] << "��"<< endl;
	cout << "���л�����" << counts[1] << "��" << endl;
	cout << "�������ԣ�" << counts[2] << "��" << endl;
	if (writeInfo("d:\\out.txt", infos) == true)
	{
		cout << "д�ļ��ɹ�"<<endl;
	}
	else
	{
		cout << "���ļ�ʧ��"<<endl;
	}
	vector <string> res = findInvalidSfzh(infos);
	cout << "���֤�Ŵ����������£�" << endl;
	showInfo(res);
	return 0;
}

