#!/usr/bin/python
# -*- coding: utf-8 -*-
#追加文件内容

lst = [x for x in range (20) if x % 3 ==0]
f = open("result.txt", "w")
for item in lst:
    f.write("%4d" % item)
f.write("\n")
f.close()

lst = [x for x in range (20) if x % 5 ==0]
f = open("result.txt", "a")
for item in lst:
    f.write("%4d" % item)
f.close()

print("Done.")