# 默认参数为构造类型的正确实现方法

def demo(item, lst=None):
    lst = [] if lst is None else lst
    print(id(lst))
    lst.append(item)
    return lst

print(demo('5', [1, 2, 3, 4]))
print()
print(demo('aaa', ['a', 'b', [1, 2]]))
print()
print(demo('a'))
print()
print(demo('b'))
print()
print(demo('c'))
