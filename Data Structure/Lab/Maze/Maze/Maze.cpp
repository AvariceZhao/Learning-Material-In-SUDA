#include "Maze.h"
#include "queue.h"
#include "stack.h"
#include "utility.h"
#define CONSOLE_RED "\033[31m"
#define CONSOLE_RESET "\033[0m"
#define CONSOLE_GREEN "\033[42m"
Maze::Maze(int Rows, int Cols)
{
	
        Row = Rows;
        Col = Cols;
        memset(in_path, 0, sizeof in_path);
		for (int i = 0; i <= Rows; i++)
			for (int j = 0; j <= Cols; j++)
				map[i][j] = 1;
	    

}
void Maze::init(int Rows, int Cols)
{
	cout << "����"<<Rows<<"��"<<Cols<<"�еĵ�ͼ, 0��ʾ�յأ�1��ʾ�ϰ�" << endl;
    int choice;
    cout << "ѡ������ʽ,0-�ֶ����룬1-�������,2-�ļ�����" << endl;

    cin >> choice;
    if (choice == 0)
    {   
        cout << "���ֶ�����" << Rows << "��" << Cols << "�е�����" << endl;

        for (int i = 1; i <= Rows; i++)
            for (int j = 1; j <= Cols; j++)
                cin >> map[i][j];
    }
    else if (choice == 1)
    {
        srand(time(NULL));
        for (int i = 1; i <= Rows; i++)
            for (int j = 1; j <= Cols; j++)
                map[i][j]=rand()%2;
        cout << "������ɵ�����Ϊ"<<endl;
        for (int i = 1; i <= Rows; i++)
        {
            for (int j = 1; j <= Cols; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 2)
    {
        string path, line;
        cout << "�������ļ�·��" << endl;

        cin >> path;
        ifstream iFile;
        iFile.open(path);
        while (!iFile.is_open())
        {
            cout << "·����������������" << endl;
            cin >> path;
            iFile.open(path);
        }
        for (int i = 1; i <= Rows; i++)
            for (int j = 1; j <= Cols; j++)
                iFile >> map[i][j];

        cout << "���ļ��ж�ȡ��������Ϊ" << endl;
        for (int i = 1; i <= Rows; i++)
        {
            for (int j = 1; j <= Cols; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }

}
void Maze::find_path(int sx, int sy,int tx,int ty)
{
    if (map[sx][sy] == 1)
    {
        cout << "�޷��ҵ�����㵽���յ��·��" << endl;
        return;
    }
    typedef pair<int, int> pii;
    pii pre[105][105];
    Queue<pii>q;
    stack<pii>stk;
    memset(dist, -1, sizeof dist);
    q.push({ sx,sy });
    pre[sx][sy] = { 0,0 };
    dist[sx][sy] = 0;
    int dx[8] = { 1,-1,0,0 ,1,1,-1,-1};
    int dy[8] = { 0,0,1,-1 ,1,-1,1,-1};
    while (q.get_size())
    {
        auto t = q.get_front(); q.pop();
        for (int k = 0; k < 8; k++)
        {
            int xx = t.first + dx[k], yy = t.second + dy[k];
            if (xx >= 1 && xx <= Row && yy >= 1 && yy <= Col && dist[xx][yy] == -1 && map[xx][yy] == 0)
            {
                dist[xx][yy] = dist[t.first][t.second] + 1;
                pre[xx][yy] = { t.first,t.second };
   
                q.push({ xx,yy });
            }
            if (dist[tx][ty] != -1)break;
        }
    }
    if (dist[tx][ty] == -1)
    {
        cout << "�޷��ҵ�����㵽���յ��·��" << endl;
        return;
    }
    cout <<"��̵�һ��·����Ҫ��" << dist[tx][ty]<<"��" << endl;
    pii now_palce1 = { tx,ty };
    in_path[tx][ty] = 1;
    pii temp = { 0,0 };
    while (now_palce1 != temp)
    {
        stk.push(now_palce1);
        now_palce1 = pre[now_palce1.first][now_palce1.second];
        in_path[now_palce1.first][now_palce1.second] = 1;
    }

    pii now_place = { 1,1 };
    pii target_palce = { tx,ty };
    cout << "����·��Ϊ:" << endl;

    while (!stk.empty())
    {
        auto temp = stk.top(); stk.pop();
        cout <<"(" << temp.first << "," << temp.second<<")" << endl;
    }

    cout << "����ͼ��ʾ" << endl;

    for (int i = 1; i <= Row; i++)
    {
        for (int j = 1; j <= Col; j++)
        {
            if (in_path[i][j])
                cout << CONSOLE_GREEN <<"��"<<CONSOLE_RESET;
            else
            {
                if (map[i][j] == 0)
                    cout << "��";
                else
                    cout<< CONSOLE_RED << "��"<< CONSOLE_RESET;
            }
        }
        cout << endl;
    }
    cout << "�Ƿ�ѡ��·���鿴·��������(Y/N) (������Ҫ���Ľϳ�ʱ�����)"<<endl;
    string choice;
    cin >> choice;
    if(choice=="y"||choice=="Y")
        cout << "����" << count_path(sx, sy, tx, ty) << "��·��" << endl;


    return;

}

int Maze::count_path(int sx,int sy,int tx,int ty)
{
    memset(st, 0, sizeof st);
    if (map[sx][sy] == 1)
        return 0;
    dfs(sx, sy, tx, ty);
    return pathNum;
}
void Maze::dfs(int x, int y, int tx, int ty)
{
    if (x == tx && y == ty)
    {
        pathNum++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && xx <= Row && yy >= 1 && yy <= Col && !st[xx][yy] && map[xx][yy] == 0)
        {
            st[xx][yy] = 1;
            dfs(xx, yy,tx,ty);
            st[xx][yy] = 0;
        }
    }
}