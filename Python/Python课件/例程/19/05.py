#!/usr/bin/python
# -*- coding: utf-8 -*-
#实用正则表达式模式匹配举例

import re

m = re.match(r"^\w+([.]\w+)?[@]\w+[.]\w+([.]\w+)?$", "demo@suda.edu.cn")
if m != None:
    print(1, m.group())
else:
    print("1 Not found.")

m = re.match(r"^\w+([.]\w+)?[@]\w+[.]\w+([.]\w+)$", "demo@suda")
if m != None:
    print(2, m.group())
else:
    print("2 Not found.")


m = re.search(r"\w+([.]\w+)?[@]\w+[.]\w+([.]\w+[a-zA-Z])", "电子邮箱地址demo@suda.edu.cn是一个电子邮箱地址")
if m != None:
    print(3, m.group())
else:
    print("3 Not found.")

m = re.search(r"[a-zA-Z]\w+([.]\w+)?[@]\w+([.]\w+[a-zA-Z])", "电子邮箱地址demo@suda.edu.cn是一个电子邮箱地址")
if m != None:
    print(4, m.group())
else:
    print("4 Not found.")


m = re.search(r"[a-zA-Z]\w+([.]\w+)?[@]\w+[.]\w+([.]\w+)[a-zA-Z]", "电子邮箱地址demo@suda.edu这是一个电子邮箱地址")
if m != None:
    print(5, m.group())
else:
    print("5 Not found.")

m = re.search(r"[a-zA-Z]\w*([.]\w+)?[@]\w+[.]\w+([.]\w*)[a-zA-Z]", "电子邮箱地址d@suda.edu.c这是一个电子邮箱地址")
if m != None:
    print(6, m.group())
else:
    print("6 Not found.")
