#迭代过程中删除元素（错例分析）

lst = [32, 1, 0, 101, 0, 0, 5, 8, 12]

for item in lst:
    if item == 0:
        lst.remove(item)
print(lst)

