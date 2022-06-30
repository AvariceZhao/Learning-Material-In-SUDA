#!/usr/bin/python
# -*- coding: utf-8 -*-
#格式化字符串 - 字符串的 format 函数2

day = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
mon = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
fev = [1, 2, 1, 3, 1, 2, 2, 3, 1, 1, 1, 0]

pack = list(zip(mon, day, fev))

formatter = "{0[0]} has {0[1]} days and {0[2]} festival(s)".format
for item in map(formatter, pack):
    print(item)
print("-"*60, 1)

#等价方法
for i in range(12):
    print("{0[0]} has {0[1]} days and {0[2]} festival(s)".format(pack[i]))
