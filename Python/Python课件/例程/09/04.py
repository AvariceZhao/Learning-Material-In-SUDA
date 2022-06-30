#走廊尽头的门

import random

max = 1000
layer = 6
lst = [0] * (layer + 1)
for i in range(max):
    c = 0
    for j in range(layer):
        c += random.randint(0,1)
    lst[c] += 1
print(lst)
print(sum(lst))

