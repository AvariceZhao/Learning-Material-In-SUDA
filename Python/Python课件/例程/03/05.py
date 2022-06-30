#列表的原地操作和非原地操作

lst1 = list(range(1,15,3))
print(lst1, id(lst1))

lst1.append(100)
print(lst1, id(lst1))

lst1.extend([200, 300])
print(lst1, id(lst1))

lst1 += [400, 500]
print(lst1, id(lst1))

lst1 = lst1 + [600, 700]
print(lst1, id(lst1))
