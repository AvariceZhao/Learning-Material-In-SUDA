#循环优化与精确计时

import random
import timeit

x = [random.random() for i in range(10000)]
k = 1.001

# 方法一
t = timeit.default_timer()
s = 0
for i in range(len(x)):
    s += x[i] * (k ** i)
t1 = timeit.default_timer() - t
print("计算结果 = %.4f, 耗时 = %.9f" % (s, t1))

# 方法二
kn = 1
t = timeit.default_timer()
s = 0
for i in range(len(x)):
    s += x[i] * kn
    kn *= k
t2 = timeit.default_timer() - t
print("计算结果 = %.4f, 耗时 = %.9f" % (s, t2))

if t1 > t2:
    print("节省时间%.1f%%" % ((t1 - t2) / t1 * 100))
else:
    print("多耗时间%.1f%%" % ((t2 - t1) / t1 * 100))