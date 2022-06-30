#使用 sort 函数和 sorted 函数的简单排序

import random

lst1 = list(range(10))
random.shuffle(lst1)
print(lst1)
lst1.sort()
print(lst1)
print()

random.shuffle(lst1)
print(lst1)
lst2 = sorted(lst1, reverse = True)
print(lst1)
print(lst2)
print()

random.shuffle(lst1)
print(lst1)
lst1.reverse()
print(lst1)