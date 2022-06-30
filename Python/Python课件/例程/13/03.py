# 函数的返回和返回值

def func1(a, b):
    return a + b

def func2(a):
    a.append(a[0] + a[1])
    return None

a = 1
b = 2

print(func1(a, b))

lst = [a, b]
func2(lst)
print(lst)
