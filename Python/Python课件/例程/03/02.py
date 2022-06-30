#列表创建、迭代遍历列表、定位和计数的元素

lst = []
print(lst, id(lst))

lst = [2, 4, 6, 6, 7]
print(lst, id(lst))

print("-" * 40)
#迭代访问列表元素
for item in lst:
    print(item)
print("-" * 40)

#通过下标迭代访问列表元素
for i in range(len(lst)):
    lst[i] += 1
print(lst, id(lst))

print(lst.index(7))
#print(lst.index(1))
print(lst.count(7))
print(lst.count(1))
