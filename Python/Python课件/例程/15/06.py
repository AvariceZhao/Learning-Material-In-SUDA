#!/usr/bin/python
# -*- coding: utf-8 -*-
#求列表中的最大值实现方法对比

import functools

def maxx(x):
    if len(x) == 0:
        return None
    m = x[0]
    for i in x:
        if i > m:
            m = i
    return m

def large(x, y):
    return x if x > y else y

a = [123, 234, 1001, 100, 967, 18]
print(functools.reduce(large, a))
print(maxx(a))
print(max(a))