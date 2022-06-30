#!/usr/bin/python
# -*- coding: utf-8 -*-
#reduce使用举例

import functools

def add_mod10(x, y):
    return (x + y) % 10

def cat(x, y):
    return int(str(x)+str(y))


a = [123, 234, 1001, 100, 967, 18]
print(functools.reduce(add_mod10, a))
print(functools.reduce(cat, a))

