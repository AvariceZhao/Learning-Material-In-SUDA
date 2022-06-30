#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式简单模式串匹配

import re
test_str = "我们四个人的学号分别是1850302345、1960401234、1840100205和1927300014。\
我的电话号码是195123456741"

m = re.findall(r"[0-9]+", "我有12个苹果和35个桔子")
if m != None:
    print(1, m)
else:
    print("1 Not found.")

m = re.findall(r"\d+", "我有12个苹果和35个桔子")
if m != None:
    print(2, m)
else:
    print("2 Not found.")

m = re.findall(r"18[0-9]{8}", test_str)
if m != None:
    print(3, m)
else:
    print("3 Not found.")

m = re.findall(r"19[0-9]{8}", test_str)
if m != None:
    print(4, m)
else:
    print("4 Not found.")

m = re.findall(r"19[0-9]{8}\b", test_str)
if m != None:
    print(5, m)
else:
    print("5 Not found.")

m = re.findall(r"[0-9]{10}\b", test_str)
if m != None:
    print(6, m)
else:
    print("6 Not found.")

m = re.findall(r"([0-9]{10})\D", test_str)
if m != None:
    print(7, m)
else:
    print("7 Not found.")

