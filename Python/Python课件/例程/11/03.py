#位置参数 -> 普通参数

def demo(a, b):
    print(a)
    print(b)
    print("-" * 40)
    return

demo(5, [1, 2, 3, 4])
demo([1, 2, 3, 4], 5)
