#浮点数计算的不精确性

import math

#浮点数多次计算
a = 2
b = math.sqrt(a)
c = b * b
print(c)

#浮点数使用整数运算符
d = 6.3 // 2.1
e = 6.3 % 2.1
print(d, e)

#浮点数相等的判定
print(a == c)

if ( abs(a - c) < 1e-9 ):
    print("True")
else:
    print("False")
