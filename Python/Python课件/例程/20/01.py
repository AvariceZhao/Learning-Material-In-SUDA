#!/usr/bin/python
# -*- coding: utf-8 -*-
#文件名中的转义符


f = open("result.txt", "r")
if f == None:
    print("文件打开错误")
else:
    print("文件打开正确")
    f.close()
