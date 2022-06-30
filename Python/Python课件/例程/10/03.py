#函数应用举例
import math

def circle(r):
    s = math.pi * r * r
    return s

def length(r):
    l = math.pi * r * 2
    return l

r = float(input("r = "))
h = float(input("h = "))

print("圆柱的体积：%8.3f" % (circle(r) * h))
print("圆柱表体积：%8.3f" % (circle(r) * 2 + length(r) * h))
