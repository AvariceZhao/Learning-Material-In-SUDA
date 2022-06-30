#递归排序

def cut(lst):
    a1, a2 = [], []
    for item in lst[1:]:
        a2.append(item) if item > lst[0] else a1.append(item)
    return a1, a2

def sort(lst):
    if len(lst) <= 1:
        return lst
    a1, a2 = cut(lst)
    return sort(a1) + [lst[0]] + sort(a2)

if __name__ == '__main__':
    print(sort([3391, 34, 25, 7, 101, 2001]))
    print(sort([3391, 34, 7, 34, 101, 2001]))
    print(sort([3391, 2001, 101, 34, 25, 7]))
    print(sort([7, 25, 34, 101, 2001, 3391]))
    print(sort([3391, 34, 25]))
    print(sort([3391, 25]))
    print(sort([3391]))
    print(sort([]))
