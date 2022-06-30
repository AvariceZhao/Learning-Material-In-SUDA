#验证切片操作是浅拷贝

lst1 = list(range(10))
lst1.insert(1, [1,2,3])
lst2 = lst1[:5]
print(lst1)
print(lst2)
print(id(lst1))
print(id(lst2))
print()

lst1[0] = 100
lst1[1][0] = 200
print(lst1)
print(lst2)
