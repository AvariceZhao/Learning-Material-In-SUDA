#!/usr/bin/python
# -*- coding: utf-8 -*-
#主动抛出异常

def exception_demo():
    a, b = 5, -1
    try:
        if b < 0:
            raise ValueError
        else:
            d = a / (b - 1)
            print("d =", d)
    except ZeroDivisionError:
        return 1
    except ValueError:
        return 2
    except BaseException as e2:
        return 3
    return 0

if __name__ == '__main__':

    errorcode =  exception_demo()

    if errorcode == 1:
        print("除法异常")
    elif errorcode == 2:
        print("用户自定义异常，值错误")
    elif errorcode == 3:
        print("其他异常")
    else:
        print("没有异常")