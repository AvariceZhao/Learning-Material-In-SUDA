#include "Life.h"
#include "utility.h"

using namespace std;


int main()
{
   
    Life configuration; //������Ϸ��
    configuration.initializeGrid(configuration.autoPlay, configuration.interval);//��ʼ��
    configuration.mainLoop();

    return 0;
}

