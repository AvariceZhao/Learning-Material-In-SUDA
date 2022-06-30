#切片操作

import random

lst1 = list(range(20))
#random.shuffle(lst1)
print(lst1)
print()

print(lst1[1:17:2])
print(lst1[:17:2])
print(lst1[1::2])
print(lst1[1:17:])
print(lst1[1:17])
print(lst1[::2])
print(lst1[1::])
print(lst1[:17:])
print(lst1[::])
