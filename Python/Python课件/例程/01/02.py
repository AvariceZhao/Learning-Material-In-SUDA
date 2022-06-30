#计算通过两点的最小圆的面积
import math

x1 = float(input("x1 = "))
y1 = float(input("y1 = "))
x2 = float(input("x2 = "))
y2 = float(input("y2 = "))

dx = x1 - x2
dy = y1 - y2
s = (dx * dx + dy * dy) / 4 * 3.14159

print("s =", s)
