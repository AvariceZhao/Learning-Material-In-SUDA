#模块含模块名判断
import math

def circle(r):
    s = math.pi * r * r
    return s

def length(r):
    l = math.pi * r * 2
    return l

if __name__=="__main__":
    r = float(input("r = "))
    h = float(input("h = "))

    print("圆柱的体积：%8.3f" % (circle(r) * h))
    print("圆柱表体积：%8.3f" % (circle(r) * 2 + length(r) * h))
