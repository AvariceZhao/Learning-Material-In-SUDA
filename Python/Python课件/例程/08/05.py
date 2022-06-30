#列表推导式
import random

lst = [x for x in range(50) if x % 3 == 0]
print(lst)

lst = [p for p in range(2, 50) if 0 not in [p % d for d in range(2, p - 1)]]
print(lst)

lst = [random.randint(11, 99) for i in range(10)]
print(lst)

lst1 = [item for item in lst if item % 5 != 0 ]
print(lst1)

lst2 = [item for item in [random.randint(11, 99) for i in range(10)] if item % 5 != 0 ]
print(lst2)

lst3 = [item for item in [random.randint(11, 99) for i in range(10)] if 0 not in [item % d for d in [2, 3, 5, 7]]]
print(lst3)

lst5 = [[x, y] for x in range(3) for y in range(4)]
print(lst5)

lst6 = [[row[i] for row in lst5] for i in range(len(lst5[0]))]
print(lst6)
