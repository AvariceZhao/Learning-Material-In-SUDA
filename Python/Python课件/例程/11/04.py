#位置参数 -> 缺省参数

def demo(a, b = 0, c = 1, d = 2):
    print(a)
    print(b)
    print(c)
    print(d)
    print("-" * 40)
    return

demo(5, [1, 2, 3, 4], 4, "hello")
demo([1, 2, 3, 4])
demo(100, 200, "hello")
