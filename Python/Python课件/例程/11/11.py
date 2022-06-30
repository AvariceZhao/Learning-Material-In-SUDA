#序列解包 -> 可变长参数

def demo(a, b, c, *p):
    print(a)
    print(b)
    print(c)
    print(p)
    print("-" * 40)
    return

demo(*[1, 2, 3])
demo(*"keyword")
demo(*[10, 20, 30, 40, 50])