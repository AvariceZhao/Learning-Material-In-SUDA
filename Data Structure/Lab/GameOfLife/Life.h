#pragma once
#include "utility.h"

#define maxCol 60
#define maxRow 60

class Life
{
public:

    void initializeGrid(int &autoPlay,int &Speed);//��ʼ��
    void updateGrid();//����
    void showGird();//չʾ
    void mainLoop();
    int autoPlay = 0, interval = 1000;//�Ƿ��Զ����š������ٶ�
 

private:
    int Generations = 0;//��ǰ����
    int Rows, Cols;//����
    int Grid[maxRow + 2][maxCol + 2];
    int calcNeighbour(int row, int col);
    void setGrid(int row, int col);
};

bool UserSayYes(DoubleBuffer &db);


