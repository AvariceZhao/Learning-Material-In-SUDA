#常用内置函数

import random

l1 = list(range(10))
random.shuffle(l1)
print(l1)

print(min(l1))
print(max(l1))
print(sum(l1))
print(sum(l1)/len(l1))

l2=[100, 200, 300]
print(list(zip(l1, l2)))

l1.insert(3, [100, 200, 300])
print(l1)
print(list(enumerate(l1)))