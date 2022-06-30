#蒙特卡洛法求圆周率

import math, random
n = 10000000
j = 0
for i in range(n):
    x = random.random()
    y = random.random()
    j = j + ( x * x + y * y <= 1.0 )
print(j / n * 4)
