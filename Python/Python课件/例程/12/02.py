#样题实现后的文件

def func1(a, b):
    if a < 1 or b < 1:
        return None
    if a < b:
        a, b = b, a
    c = 1
    while c != 0:
        c = a % b
        a, b = b, c
    return a

def func2(a):
    if str(type(a)) != "<class 'int'>":
        return False
    if a < 2:
        return False
    lst = [a % d for d in range(2, a - 1)]
    return False if 0 in lst else True

if __name__ == "__main__":
    print(func1(17, 51))
    print(func1(24, 18))
    print(func1(-1, 51))
    print(func1(-1, 0))
    print(func1(123, 234))
    print("-" * 50)
    print(func2(9))
    print(func2(19))
    print(func2(2))
    print(func2(1))
    print(func2(2.1))
