#pragma once
#include "utility.h"

#define maxCol 60
#define maxRow 60

class Life
{
public:

    void initializeGrid(int &autoPlay,int &Speed);//初始化
    void updateGrid();//更新
    void showGird();//展示
    void mainLoop();
    int autoPlay = 0, interval = 1000;//是否自动播放、播放速度
 

private:
    int Generations = 0;//当前代数
    int Rows, Cols;//行列
    int Grid[maxRow + 2][maxCol + 2];
    int calcNeighbour(int row, int col);
    void setGrid(int row, int col);
};

bool UserSayYes(DoubleBuffer &db);


