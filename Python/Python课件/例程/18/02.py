#!/usr/bin/python
# -*- coding: utf-8 -*-
#格式化字符串 - 字符串的 format 函数1

day = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
mon = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
fev = [1, 2, 1, 3, 1, 2, 2, 3, 1, 1, 1, 0]

pack = list(zip(mon, day, fev))

for a, b, c in pack:
    print("{0} has {1} days and {2} festival(s)".format(a, b, c))
print("-"*60, 1)

for a, b, c in pack:
    print("{p1} has {p2} days and {p3} festival(s)".format(p1=a, p2=b, p3=c))
print("-"*60, 2)

for item in pack:
    print("{0[0]} has {0[1]} days and {0[2]} festival(s)".format(item))
print("-"*60, 3)

for item in pack:
    print("{0[0]} has {0[1]} days and {0[2]} festival(s)".format(list(item)))
print("-"*60, 4)

for item in pack:
    print("{0} has {1} days and {2} festival(s)".format(*item))
