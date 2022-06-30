#!/usr/bin/python
# -*- coding: utf-8 -*-
#字符串分割成整数求和

number_str = "73,  123,456,     789, -12, 101"
number_list = number_str.split(",")
#print(number_list)
sum = 0
for s in number_list:
    #print(s)
    sum += int(s)
print(sum)
