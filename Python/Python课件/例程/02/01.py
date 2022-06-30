#对象模型

def f(x):
    return x*x

a = 1
b = [1, 2, 3]
c = {1, 2, 3}
d = range(10)
print(id(a), type(a))
print(id(b), type(b))
print(id(c), type(c))
print(id(d), type(d))
print(id(1), type(1))
print(id(True), type(True))
print(id(None), type(None))
print(id(f), type(f))
