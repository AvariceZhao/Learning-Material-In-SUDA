#生成器

import random

def g_pixel(n):
    s = 0
    while s < n:
        a = random.randint(100, 999)
        b = random.randint(100, 999)
        c = random.randint(100, 999)
        yield a, b, c
        s += 1
    return

g = g_pixel(2)
lst = [item for item in g]
print(lst)

g = g_pixel(3)
lst = [list(item) for item in g]
print(lst)

g = g_pixel(4)
tup = tuple(item for item in g)
print(tup)

g = g_pixel(5)
dic = dict(item[0:2] for item in g)
print(dic)
