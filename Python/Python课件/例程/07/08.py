#可迭代对象和迭代器

r1 = range(5)
r2 = reversed(r1)

print("r1的类型：%s" % type(r1))
print("r2的类型：%s" % type(r2))
print()

for i in r1:
    print("r1->", i)
print()
for i in r2:
    print("r2->", i)

print("-" * 40)

for i in r1:
    print("r1->", i)
print()
for i in r2:
    print("r2->", i)
