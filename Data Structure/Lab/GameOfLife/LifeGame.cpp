#include "Life.h"

bool UserSayYes(DoubleBuffer& db)//是否看下一代
{
    string Command;
    cin >> Command;
    if (Command == "Y" || Command == "y" || Command == "YES" || Command == "yes" || Command == "1")
        return true;
    else
        return false;
}

void Life::mainLoop()
{
    system("cls");
    (*this).showGird();
    Sleep((*this).interval);
    system("cls");
    DoubleBuffer db;
  

    if ((*this).autoPlay)//自动播放
    {
        while (true)
        {
            (*this).updateGrid();
            (*this).showGird();
            db.show();
            Sleep((*this).interval);

        }
    }
    else//手动播放
    {
        db.close();
        (*this).showGird();
        cout << "Continue viewing new generations? (Y/N)" << endl;
     
        while (UserSayYes(db))
        {

            system("cls");
            (*this).updateGrid();
            (*this).showGird();
            cout << "Continue viewing new generations? (Y/N)" << endl;

        }
    }
}
void Life::setGrid(int row, int col)//设定表格大小并初始化表格
{


    Rows = max(0,row);
    Cols = max(0,col);

    for (int i = 1; i <= Rows; i++)
        for (int j = 1; j <= Cols; j++)
            Grid[i][j] = 0;
}

void Life::initializeGrid(int &autoPlay,int &Speed)//初始化表格，选择播放设置
{
    memset(Grid, -1, sizeof Grid);

    int rows, cols, liveNums, speed;
    string choice;
    cout << "Please input the number of rows and the number of columns:(no more than 50*50)" << endl;
    cin >> rows >> cols;
    setGrid(min(rows,50), min(cols,50));


    cout << "Whether use auto play(Y/N)" << endl;
    cin >> choice;
    if (choice == "Y" || choice == "y")
    {
        autoPlay = 1;
        cout << "Please set the playback interval (ms)"<<endl;
        cin >> speed;
        Speed = speed;
    }
    else
        autoPlay = 0;

    int choice0 = 0;
    cout << "Please choose the way to generate the grid  0-random 1-input coordinates 2-from file" << endl;
    cin >> choice0;
    if (choice0 == 0)
    {
        srand((unsigned)time(NULL));
        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= cols; j++)
                Grid[i][j] = rand() % 2;
        return;
    }
    else if (choice0==1)
    {

        cout << "Please input the number of living cells" << endl;
        cin >> liveNums;

        cout << "Please input " << liveNums << " living cell coordinates" << endl;
        
        int nums = 0;
        while(nums<liveNums)
        {
            int x, y;
            cin >> x >> y;
            if (x >= 1 && x <= Rows && y >= 1 && y <= Cols)
                Grid[x][y] = 1, nums++;
            else
            {
                cout << "invalid coordinates,input again" << endl;
            }
        }

    }
    else
    {
        cout << "Please input the path of the file"<<endl;
        string path, line;
        cin >> path;
        ifstream iFile;
        iFile.open(path);
        while (!iFile.is_open())
        {
            cout << "Path error ,input the path again" << endl;
            cin >> path;
            iFile.open(path);
        }
        for (int i = 1; i <= Rows; i++)
        {
            getline(iFile, line);
            while (line.size() < Cols)line += " ";

            for (int j = 0; j < Cols; j++)
            {
                if (line[j] != ' ')Grid[i][j + 1] = 1;
                else Grid[i][j+1] = 0;
            }   
        }
     
    }
}


int Life::calcNeighbour(int row, int col)//计算周围活细胞数量
{
    int Num = 0;
    for (int i = row - 1; i <= row + 1; i++)
        for (int j = col - 1; j <= col + 1; j++)
            Num += (Grid[i][j] == 1);
    Num -= Grid[row][col];
    return Num;
}

void Life::updateGrid()//更新表格
{
    Generations++;

    int newGrid[maxRow + 2][maxCol + 2];

    memset(newGrid, 0, sizeof newGrid);

    for (int i = 1; i <= Rows; i++)
    {
        for (int j = 1; j <= Cols; j++)
        {
            int Num = calcNeighbour(i, j);

            if ((Num == 2 || Num == 3) && Grid[i][j])
                newGrid[i][j] = 1;
            if (Grid[i][j] && !(Num == 2 || Num == 3))
                newGrid[i][j] = 0;
            if (!Grid[i][j] && Num == 3)
                newGrid[i][j] = 1;

        }
    }
    for (int i = 1; i <= Rows; i++)
        for (int j = 1; j <= Cols; j++)
            Grid[i][j] = newGrid[i][j];

}



void Life::showGird()//展示
{   
    cout << "This is the grid of " << Generations << " th generation" << endl;
    for (int i = 1; i <= Rows; i++)
    {
        for (int j = 1; j <= Cols; j++)
            cout << (Grid[i][j] ? "x" : " ");
        cout << endl;
    }

    

}