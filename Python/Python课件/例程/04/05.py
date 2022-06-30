#利用切片对列表的增删改和取切片

import random

lst1 = list(range(10))
random.shuffle(lst1)
print(lst1, id(lst1))
print()

#通过切片操作列表
lst1[3:5] += [100, 200, 300]
print(lst1, id(lst1))
lst1[3:5] = []
print(lst1, id(lst1))
lst1[3:5] = [400]
print(lst1, id(lst1))
print()

#取出切片使用
lst2 = lst1[::]
print(lst2, id(lst2))
lst3 = lst1[8:4:-1]
print(lst3, id(lst3))