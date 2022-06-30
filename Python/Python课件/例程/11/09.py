#序列解包 -> 普通参数

def demo(a, b, c):
    print(a)
    print(b)
    print(c)
    print("-" * 40)
    return

demo(*[1, 2, 3])
demo(*"key")