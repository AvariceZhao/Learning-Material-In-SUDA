#用 zip 实现并列迭代

a = [87, 91, 65, 34, 80]
b = [99, 79, 85, 55, 82]
c = [81, 91, 67, 43, 81]

#??

for i in range(len(a)):
    if a[i] >= 80 and b[i] >= 80 and c[i] >= 80:
        print(i, ":", a[i], b[i], c[i])

print("-" * 40)

i = 0
for a1, b1, c1 in zip(a, b, c):
    if a1 >= 80 and b1 >= 80 and c1 >= 80:
        print(i, ":", a1, b1, c1)
    i += 1
