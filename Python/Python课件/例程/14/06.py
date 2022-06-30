#递归求最大值

def f1(lst):
    if lst == []:
        return None
    s = lst[0]
    for item in lst:
        s = item if item > s else s
    return s

def f2(lst):
    L = len(lst)
    if L == 0:
        return None
    if L == 1:
        return lst[0]
    else:
        return lst[L - 1] if lst[L - 1] >= f2(lst[:L - 1]) else f2(lst[:L - 1])

print(f1([71, 3, 6, 29, -1, 109, 108]))
print(f2([71, 3, 6, 29, -1, 109, 108]))