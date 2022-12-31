#include "utility.h"
#include "stack.h"
#include "queue.h"
#include "Maze.h"
int main()
{
    int n, m;
    cout << "输入地图的行数和列数，不超过100*100" << endl;
    while (cin >> n >> m)
    {
        if (n >= 0 && n <= 100 && m >= 0 && m <= 100)break;
        else cout << "数据不合法，请重新输入" << endl;
    }
    Maze maze(n, m);
    maze.init(n,m);
    cout << "输入起点坐标和终点坐标" << endl;
    int sx, sy, tx, ty;
    cin >> sx >> sy >>tx >> ty;
    maze.find_path(sx,sy,tx,ty);
    


    return 0;
}