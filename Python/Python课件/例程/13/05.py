#两数交换的函数实现方法（多值返回的应用）

def swap1(a, b):
    a, b = b, a

def swap2(a, b):
    return b, a

x = 1
y = 2
print(x, y)
swap1(x, y)
print(x, y)
x, y = swap2(x, y)
print(x, y)
