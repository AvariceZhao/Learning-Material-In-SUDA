#循环中 else 的激活条件

lst = range(5)

for i in lst:
    print(i)
else:
    print("finish")

print("-" * 40)

for i in []:
    print(i)
else:
    print("finish")

print("-" * 40)

for i in lst:
    if i > 3:
        break
    print(i)
else:
    print("finish")