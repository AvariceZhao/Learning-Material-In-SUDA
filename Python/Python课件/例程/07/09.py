#生成迭代器

r1 = range(5)       #可迭代对象
r2 = iter(r1)       #迭代器

for i in r1:
    print("r1->", i)
print()
for i in r2:
    print("r2->", i)
    if i == 2:
        break
print("=" * 20)
for i in r2:
    print("r2->", i)

print("-" * 40)

for i in r1:
    print("r1->", i)
print()
for i in r2:
    print("r2->", i)
