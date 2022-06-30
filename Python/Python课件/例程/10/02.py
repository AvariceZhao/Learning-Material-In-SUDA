#函数定义的位置

def f1():
    print("This is F1.")
    f2()
    return

def f2():
    print("This is F2.")
    return

f1()
f2()
