#!/usr/bin/python
# -*- coding: utf-8 -*-
#lambda表达式使用举例

import math

def reverse(n):
    return int(str(n)[::-1])

f = lambda a, b, c : [(-b+math.sqrt(b*b-4*a*c))/2*a, (-b-math.sqrt(b*b-4*a*c))/2*a] if b*b-4*a*c>=0 else None
g = lambda x : -1 if x < 0 else 0 if x < 100 else 1
k = lambda x : reverse(x)

print(f(1, -5, 6))
print("-"*40)
print(g(-1))
print(g(0))
print(g(99))
print(g(100))
print("-"*40)
print(k(123))
print(k(1205))
