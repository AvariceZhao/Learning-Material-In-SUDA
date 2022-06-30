#简单列表生成式

l1 = list(range(50))
l2 = [x for x in l1 if x % 3 == 0]
print(l2)

l3 = [x for x in l1 if x % 10 == 9]
print(l3)

l4 = [x for x in l3 if x% 3 == 0]
print(l4)

l5 = [x for x in [x for x in l1 if x % 10 == 9] if x % 3 == 0]
print(l5)
