#推导式

lst = [x for x in range(100) if x % 13 == 0]
print(lst)
print()

tup = (x for x in range(100) if x % 13 == 0)
print(tup)
print(tuple(tup))
print()

sst = {x for x in range(100) if x % 13 == 0}
print(sst)
print()

dic = {k: k * k for k in range(1, 5)}
print(dic)

lst = [(x, y) for x, y in dic.items()]
print(lst)

print(list(dic.items()))
print()
