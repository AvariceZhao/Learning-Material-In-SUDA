#!/usr/bin/python
# -*- coding: utf-8 -*-
#全局变量定义位置与使用位置的关系

def demo1():
    print(x + 1)
    return


x = 5
def demo2():
    print(x + 2)
    return

demo1()
demo2()
