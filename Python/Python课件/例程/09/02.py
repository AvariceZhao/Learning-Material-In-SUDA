#奇数阶魔方阵（生成式初始化）

import sys

k = int(input("魔方阵阶数："))
if k % 2 != 1:
    print("输入不是奇数。")
    sys.exit()

a = [[0] * k for i in range(k)]
x, y = k // 2, 0
for i in range(1, k ** 2 + 1):
    a[y][x] = i
    y = (y - 1) % k if i % k else y + 1
    x = (x + 1) % k if i % k else x
    
for i in range(k):
    for j in range(k):
        print("%4d" % (a[i][j]), end = "")
    print()
