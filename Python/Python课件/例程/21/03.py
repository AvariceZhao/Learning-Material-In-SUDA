#!/usr/bin/python
# -*- coding: utf-8 -*-
#综合异常

def exception_demo_3():
    a, b, c = 5, 1, "123"
    try:
        d = a / ( b - 1)
        e = a / c
        f = open("test.txt", "r")
        print("d = ", d)
        print("e = ", e)
    except ZeroDivisionError:
        print("除法异常")
    except TypeError:
        print("类型异常")
    except BaseException as e:
        print("其他异常：", e)
    else:
        return False
    finally:
        print("OK")
    return True


if exception_demo_3():
    print("Exceptions")
else:
    print("No Exception")