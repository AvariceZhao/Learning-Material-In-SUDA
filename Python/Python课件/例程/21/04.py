#!/usr/bin/python
# -*- coding: utf-8 -*-
#综合异常的集中处理方式

def exception_demo():
    a, b, c = 5, 1, "123"
    try:
        d = a / (b - 1)
        e = a / c
        f = open("test.txt", "r")
        print("d = ", d)
        print("e = ", e)
    except ZeroDivisionError:
        return 1
    except TypeError:
        return 2
    except BaseException as e:
        return 3
    return 0

if __name__ == '__main__':

    errorcode =  exception_demo()

    if errorcode == 1:
        print("除法异常")
    elif errorcode == 2:
        print("类型异常")
    elif errorcode == 3:
        print("其他异常")
    else:
        print("没有异常")