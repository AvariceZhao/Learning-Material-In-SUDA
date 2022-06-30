#循环内外层同名变量的关系

for i in range(3):
    for j in range(5):
        print("%3d" % (i * j * 2), end = "")
    print()

print("-" * 20)

for i in range(3):
    a = 1
    for i in range(5):
        a = 2
        print("%3d" % (i * i * a), end = "")
    print()

