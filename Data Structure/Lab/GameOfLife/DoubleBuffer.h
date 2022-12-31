#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class DoubleBuffer {
private:
    HANDLE l_buffer1;
    HANDLE l_buffer2;
    HANDLE l_stdBuffer;
    TCHAR* _data = NULL;
    int nowActive;

    void bufferSwitch();

public:
    DoubleBuffer();
    void show(); //展示
    void close(); //关闭
    void clear(); //清空缓冲区
 
};