#递归求斐波那契数列

def f1(n):
    a, b = 1, 1
    if n < 0:
        return None
    elif n == 1 or n == 2:
        return 1
    for i in range(n - 2):
        a, b = b, a + b
    return b

def f2(n):
    if n < 0:
        return None
    elif n == 1 or n == 2:
        return 1
    else:
        return f2(n - 1) + f2(n - 2)

def f3(n):
    return None if n < 0 else 1 if n == 1 or n == 2 else f3(n - 1) + f3(n - 2)

print(f1(5))
print(f1(10))
print(f1(15))
print(f2(5))
print(f2(10))
print(f2(15))
print(f3(15))
