#使用函数进行自定义排序

import random

lst1 = list(range(10, 20))
random.shuffle(lst1)
print(lst1)

# 自然排序的内在语义
lst1.sort(key=lambda x: x, reverse=False)
print(lst1)
print()

# 自定义排序关键字
random.shuffle(lst1)
print(lst1)
lst1.sort(key=lambda x: x % 3, reverse=False)
print(lst1)

# 自定义排序关键字
lst1 = [[3, 4, 5], [1, 3, 4], [2, 2, 2]]
print(lst1, id(lst1))
lst1.sort(key=lambda item: item[2])
print(lst1, id(lst1))
print()

# 自定义排序关键字
lst2 = [[3, 4, 5], [1, 3, 4], [2, 2, 2]]
lst3 = sorted(lst2, key=lambda item: item[2], reverse=False)
print(lst2, id(lst2))
print(lst3, id(lst3))