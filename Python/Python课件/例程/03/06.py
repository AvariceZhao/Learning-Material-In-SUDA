#列表的原地操作和非原地操作的性能差异

import time

lst = list(range(10))
n = 10000

start_CPU = time.time()
for i in range(n):
    lst += [400, 500]
end_CPU = time.time()
print("Method 1: %f CPU seconds" % (end_CPU - start_CPU))

start_CPU = time.time()
for i in range(n):
    lst = lst + [400, 500]
end_CPU = time.time()
print("Method 2: %f CPU seconds" % (end_CPU - start_CPU))
