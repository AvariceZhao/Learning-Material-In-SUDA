#!/usr/bin/python
# -*- coding: utf-8 -*-
#类型异常

def exception_demo_2():
    a, b = 5, "123"
    try:
        #c = a / b
        c = a / int(b)
        print("c =", c)
    except TypeError:
        print("类型异常")
    else:
        return False
    return True

if exception_demo_2():
    print("Exceptions")
else:
    print("No Exception")
