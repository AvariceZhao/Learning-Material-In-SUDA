#适应多种情况的自定义列表排序

def large(a, b):
    return True if a > b else False

def less(a, b):
    return True if a < b else False

def key1(a):
    return a

def key2(a):
    return a % 100

def key3(a):
    return a % 10

def key4(a):
    return a[0]

def order(lst, key=key1, reverse=False):
    if len(lst) <= 1:
        return lst

    compare = less if reverse else large

    for i in range(len(lst) - 1):
        for j in range(i + 1, len(lst)):
            if compare(key(lst[i]), key(lst[j])):
                lst[i], lst[j] = lst[j], lst[i]
    return lst

print(order([3314, 6732, 2910, 1004, 1091, 1019], key1))
print(order([3314, 6732, 2910, 1004, 1091, 1019], reverse=True))
print(order([3314, 6732, 2910, 1004, 1091, 1019], key=key2, reverse=True))
print(order([3314, 6732, 2910, 1004, 1091, 1019], key3))
print(order([[3314, 6732], [2910, 1004], [1091, 1019]], key=key4,
            reverse=True))
print(order([[3314, 6732], [2910, 1004], [1091, 1019]], key=lambda x: x[0]))
