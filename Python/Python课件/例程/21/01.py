#!/usr/bin/python
# -*- coding: utf-8 -*-
#除法异常

def exception_demo_1():
    a, b = 5, 1
    try:
        c = a / (b - 1)
        print("c =", c)
    except ZeroDivisionError as e:
        print("除法异常")
    else:
        return False
    return True

if exception_demo_1():
    print("Exceptions")
else:
    print("No Exception")
