#!/usr/bin/python
# -*- coding: utf-8 -*-
#格式化字符串

day = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
mon = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

for i in range(12):
    print("%s has %d days." % (mon[i], day[i]))
    print(mon[i], "has", str(day[i]), "days.")
    print(mon[i] + " has " + str(day[i]) + " days.")
    print()