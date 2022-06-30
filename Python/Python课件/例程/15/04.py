#!/usr/bin/python
# -*- coding: utf-8 -*-
#map使用举例

import math, functools

def reverse(n):
    return int(str(n)[::-1])

def ele_len(x):
    return len(str(x))

a = [123, 234, 1001, 100, 967, 18]
print(list(map(reverse, a)))
print(list(map(ele_len, a)))
