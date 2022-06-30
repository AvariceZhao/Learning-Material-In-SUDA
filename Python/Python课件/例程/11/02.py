#构造类型参数传递（无返回）

def demo(a:list):
    print("    id(a) = ", id(a))
    a.append(10)
    print(a)
    print("    id(a) = ", id(a))
    return None

x, y = [5], []
print("x = ", x)
print("y = ", y)
print("id(x) = ", id(x))
print("id(y) = ", id(y))
y = demo(x)
print("x = ", x)
print("y = ", y)
print("id(x) = ", id(x))
print("id(y) = ", id(y))
y = demo(x)
print(x)
demo(x)
print(x)
print(y)
