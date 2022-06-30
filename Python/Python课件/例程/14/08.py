#递归求阶乘

def f1(n):
    if n < 1:
        return None
    s = 1
    for i in range(1, n+1):
        s *= i
    return s

def f2(n):
    if n < 1:
        return None
    if n == 1:
        return 1
    return n*f2(n-1)


print(f1(5))
print(f1(10))
print(f1(15))
print(f2(5))
print(f2(10))
print(f2(15))
