#多数值返回的实质

import math

def demo(a, b, c):
    a += 1
    b *= 2
    c /= 3
    return a, b, c


x, y, z = demo(100, 200, 300)
print(x, y, z)
x = demo(100, 200, 300)
print(x)
#x, y = demo(100, 200, 300)
#print(x, y)
