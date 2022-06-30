#生成器

import random

def g_pixel():
    while True:
        a = random.random()
        b = random.random()
        yield a, b
    return

g = g_pixel()

c = 0
for x, y in g:
    print("%10.5f%10.5f" % (x, y))
    c += 1
    if c >= 5:
        break
