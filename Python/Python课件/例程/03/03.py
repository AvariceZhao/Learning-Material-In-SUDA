#迭代过程中增加元素

lst = [32, 1, 47, 101, 3, 5, 8, 12]
print(len(lst))

c = 0
for item in lst:
    if item == 101:
        lst.append(1000)
    c += 1

print(lst)
print(len(lst))
print(c)