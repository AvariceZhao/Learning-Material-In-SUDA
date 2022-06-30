#!/usr/bin/python
# -*- coding: utf-8 -*-
#filter使用举例

import functools

def prime(x):
    return False if 0 in [x % k for k in range(2, x // 2 + 1)] else True

def ret(x):
    return True if x == int(str(x)[::-1]) else False

a = [123, 232, 1001, 7, 100, 967, 18, 19]
print(list(filter(prime, a)))
print(list(filter(ret, a)))
