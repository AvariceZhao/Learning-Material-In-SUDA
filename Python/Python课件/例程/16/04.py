#无序对象的排序

s = {301, 5, 2, -1, 78,32,0, 109}
print(sorted(s))

d = {1:301, 3:5, 2:2, 5:-1, 11:78, -2:32, 77:0, 21:109}
print(sorted(d))

d = {1:301, 3:5, 2:2, 5:-1, 11:78, -2:32, 77:0, 21:109}
print(sorted(d, key=d.__getitem__))

d = {1:301, 3:5, 2:2, 5:-1, 11:78, -2:32, 77:0, 21:109}
lst = [(k, d[k]) for k in sorted(d)]
print(lst)
lst = [(k, d[k]) for k in sorted(d, key=d.__getitem__)]
print(lst)
