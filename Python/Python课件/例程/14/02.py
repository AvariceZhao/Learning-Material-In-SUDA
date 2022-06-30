#函数做参数

def large(a, b):
    return True if a > b else False

def less(a, b):
    return True if a < b else False

def extremum(f, lst):
    if lst == []:
        return
    s = lst[0]
    for item in lst:
        if f(item, s) == True:
            s = item
    return s

print(extremum(large, [3, 6, 29, -1, 109, 109]))
print(extremum(less, [3, 6, 29, -1, 109, -1]))