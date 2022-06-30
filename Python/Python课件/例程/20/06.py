#!/usr/bin/python
# -*- coding: utf-8 -*-
#写二进制文件
import pickle

lst = [x for x in range (20) if x % 3 ==0]
n = len(lst)
f = open("result.bin", "wb")
pickle.dump(n+1, f)
for item in lst:
    pickle.dump(item, f)
    
pickle.dump([1,2,{45,78},{1:"a", 2:"b"},[9,1]], f)
f.close()
print("Done.")

