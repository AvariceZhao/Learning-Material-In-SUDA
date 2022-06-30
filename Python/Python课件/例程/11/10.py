#序列解包 -> 默认参数

def demo(a, b, c = 0):
    print(a)
    print(b)
    print(c)
    print("-" * 40)
    return

demo(*[1, 2, 3])
demo(*"key")
demo(*"w", "x")