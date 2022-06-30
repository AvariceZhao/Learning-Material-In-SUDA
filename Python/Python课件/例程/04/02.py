#列表浅拷贝
import copy

lst1 = list(range(10))
lst1.insert(2, [1,2,3])
lst2 = copy.copy(lst1)      #浅拷贝生成一个新的对象

print(lst1)
print(lst2)
print()

print(id(lst1))
print(id(lst2))
print()

lst1[1] = 100
lst1[2][1] = 200
print(lst1)
print(lst2)
print()

print(id(lst1[2]))
print(id(lst2[2]))