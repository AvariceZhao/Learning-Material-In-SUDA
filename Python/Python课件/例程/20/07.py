#!/usr/bin/python
# -*- coding: utf-8 -*-
#读二进制文件
import pickle

lst = []
f = open("result.bin", "rb")
n = pickle.load(f)
print(n)
for i in range(n):
    lst.append(pickle.load(f))
f.close()
print(lst)
print("Done.")
