#!/usr/bin/python
# -*- coding: utf-8 -*-
#局部变量屏蔽全局变量

def demo():
    a = 3
    print("    id(a) = ", id(a))
    print("    id(b) = ", id(b))
    return a

a = 1
b = 2
print("id(a) = ", id(a))
print("id(b) = ", id(b))
print("demo() = %d, a = %d" % (demo(), a))
