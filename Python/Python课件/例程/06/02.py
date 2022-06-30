#验证分支短路现象

lst = [0, 0]
if 1 < 0 or lst.append(5):
    lst[1] = 200
print(lst)
