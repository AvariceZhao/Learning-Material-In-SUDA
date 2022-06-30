#迭代过程

lst = list(range(1, 20, 3))
print("列表长度 = %d" % len(lst))

c = 0
for item in lst:
    if item == 10:
        lst.append(1000)
    print(item)
    c += 1
print("迭代次数 = %d" % c)