#奇数阶魔方阵（迭代方式初始化）

k = int(input("魔方阵阶数："))

a = []
for i in range(k):
    b = []
    for j in range(k):
        b.append(0)
    a.append(b)

y = 0
x = (k - 1) // 2
for i in range(1, k ** 2 + 1):
    a[y][x] = i
    if i % k == 0:
        y = y + 1
    else:
        if y == 0:
            y = k - 1
        else:
            y = y - 1
        if x == k-1:
            x = 0
        else:
            x = x + 1
        
for i in range(k):
    for j in range(k):
        print("%4d" % (a[i][j]), end = "")
    print()
