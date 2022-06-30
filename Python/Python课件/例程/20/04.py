#!/usr/bin/python
# -*- coding: utf-8 -*-
#读文本文件过滤并写入另一个文件
import re

linelen = 5

f = open("result.txt", "r")
data = f.readlines()
f.close()

#print(data)
data = "".join(data)
#print(data)
lst = re.findall(r"\d+", data)
print(lst)

r = []
for x in lst:
    if "3" in x or "5" in x or x[-1] == "0":
        continue
    else:
        r.append(x)
#r = [x for x in lst if "3" not in x and "5" not in x and x[-1] != "0"]
#r = list(filter(lambda x: not("3" in x or "5" in x or x[-1] == "0"), lst))
print(r, "len =", len(r))

with open("data.txt", "w") as f:
    for i in r:
        f.write(i+"\n")

print("Done.")