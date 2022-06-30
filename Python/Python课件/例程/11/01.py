#简单类型参数传递（无返回）

def demo(a):
    print("    id(a) = ", id(a))
    a += 1
    print("    id(a) = ", id(a))
    #return None

x, y = 5, 0
print("x = ", x)
print("y = ", y)
print("id(x) = ", id(x))
print("id(y) = ", id(y))
y = demo(x)
print("x = ", x)
print("y = ", y)
print("id(x) = ", id(x))
print("id(y) = ", id(y))
