#include "Life.h"
#include "utility.h"

using namespace std;


int main()
{
   
    Life configuration; //生存游戏类
    configuration.initializeGrid(configuration.autoPlay, configuration.interval);//初始化
    configuration.mainLoop();

    return 0;
}

