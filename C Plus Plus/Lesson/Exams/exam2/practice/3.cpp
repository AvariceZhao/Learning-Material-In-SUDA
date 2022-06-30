#include<bits/stdc++.h>
using namespace std;
class CLyric
{
	private:
		int 	m_Minute;			//����
		int 	m_Second;			//��
		int 	m_Millisecond; 	//����
		string m_Sentence;		//һ����
		int	  	m_SequenceId;		//��1��ʼ����ˮ��ţ�ÿ�������ظ�
		static int m_MaxId;
	
	public:
	
	CLyric(int m,int s,int ms,string sentence)
	{
		if(!(m>=0&&m<=59&&s>=0&&s<=59&&ms>=0&&ms<=999))
		{
			m_Minute=0,m_Second=0,m_Millisecond=0,m_Sentence=sentence;
			m_SequenceId=++m_MaxId;
		}
		else
		{
			m_Minute=m,m_Second=s,m_Millisecond=ms,m_Sentence=sentence;
			m_SequenceId=++m_MaxId;
		}
			
	}
	CLyric(const CLyric &temp)
	{
		m_Second=temp.m_Second;
		m_Minute=temp.m_Minute;
		m_Millisecond=temp.m_Millisecond;
		m_Sentence=temp.m_Sentence;
		m_SequenceId=++m_MaxId;
	}
	int getMinute()const
	{
		return m_Minute;
	}
	int getSecond()const
	{
		return m_Second;
	}
	int getMillisecond()const
	{
		return m_Millisecond;
	}
	string getSentence()const
	{
		return m_Sentence;
	}
	int getSequenceId()const
	{
		return m_SequenceId;
	}
	friend ostream & operator <<(ostream &out,const CLyric &temp)
	{
		out<<"["
        <<setw(2)<<setfill('0')<<temp.m_Minute<<":"
        <<setw(2)<<setfill('0')<<temp.m_Second<<":"
        <<setw(3)<<setfill('0')<<temp.m_Millisecond
        <<"] "<<temp.m_Sentence;
		return out;
	}
	CLyric operator++(int)
	{
		auto temp=*this;
		m_Second+=1;
		if(m_Second>59)
		{
			m_Minute+=1;
			m_Second=0;
		}
		if(m_Minute>59)
		{
			m_Minute=0;
		}
		return temp;
	}
	 CLyric operator+(const int  ms)
	{	
		int Millisecond=m_Millisecond,Second=m_Second,Minute=m_Minute;
		Millisecond+=ms;
        Second+=Millisecond/1000;
        Millisecond%=1000;
        Minute+=Second/60;
        Second%=60;
        Minute%=60;
        CLyric t(Minute,Second,Millisecond,m_Sentence);
		return  t;
	}
	friend void writeSong(string path, vector<CLyric> &song);
};
int CLyric ::m_MaxId=0;
int readSong(const char path[],vector<CLyric>&song)
{
	ifstream iFile;
	int ans=0,m,s,ms;string sentence;
	iFile.open(path);
	while(iFile>>m>>s>>ms>>sentence)
	{
		if(!(m>=0&&m<=59&&s>=0&&s<=59&&ms>=0&&ms<=999))
		{
			ans++;
		}
		else
		{
			song.push_back({m,s,ms,sentence});
		}
	}
	return ans;
}
void showTopN(vector<CLyric>&song,int num=0)
{
	for(int i=0;i<min((int)song.size(),num);i++)
	{
		cout<<song[i]<<endl;
	}
}
void offsetSong(vector<CLyric>&song)
{
	for(int i=0;i<(int)song.size();i++)
	{
		song[i]++;
			
	}
}
void writeSong(string path, vector<CLyric> &song){
    ofstream ofs;
    ofs.open(path.c_str());

    for(int i = 0; i < song.size(); i ++){
        ofs << song[i] << endl;
    }

    ofs.close();
}
int main()
{
	CLyric time1(61,12,125,"����֮��");
	cout << "���time1��" << endl;
	cout << "id=" << time1.getSequenceId() << " " << time1 << endl;

	CLyric time2(59, 59, 500,"˫�ع�");
	cout << "ִ�мӺ��������time2��" << endl;
	time2 = time2 + 2000;

	cout <<"id="<<time2.getSequenceId()<<" "<<time2 << endl;
	cout << "ִ�к���++�������time2��" << endl;
	time1 = time2++;
	cout << "id=" << time2.getSequenceId() << " " << time2 << endl;


	vector<CLyric> song;
	cout << "��ȡԭʼ����ļ�" << endl;
	int count=readSong("d:\\in.txt", song);
	cout << "����" << count << "�в��Ϸ�����" << endl;
	cout << "���ǰ5���ǣ�" << endl;
	showTopN(song, 5);
	offsetSong(song);
	cout << "�������ɸ���ļ�......"<<endl;
	writeSong("d:\\out.lrc", song);
	cout << "���ɸ���ļ��ɹ���"<<endl;
    system("pause");
	return 0;
}
