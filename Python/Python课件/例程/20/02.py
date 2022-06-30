#!/usr/bin/python
# -*- coding: utf-8 -*-
#分行写入文本文件

linelen = 5

lst = [x for x in range (40) if x % 3 ==0]

f = open("result.txt", "w")
c = 0
for item in lst:
    f.write("%4d" % item)
    c += 1
    if c % linelen == 0:
        f.write("\n")
f.close()
print("Done.")