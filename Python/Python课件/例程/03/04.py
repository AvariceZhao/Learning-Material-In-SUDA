#列表的赋值、列表元素的修改及列表删除

lst1 = list(range(1, 20, 3))
print(lst1, id(lst1))

lst2 = lst1
print(lst2, id(lst2))

lst1[0] = 100
print(lst2, id(lst2))

del lst1
print(lst2, id(lst2))
#print(lst1, id(lst1))
