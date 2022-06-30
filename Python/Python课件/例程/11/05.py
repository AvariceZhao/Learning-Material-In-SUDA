#位置参数 -> 可变长参数

def demo(a, *b):
    print(a)
    print(b)
    print("-" * 40)
    return

demo(5, [1, 2, 3, 4], 6, "hello")
demo(5, [1, 2, 3, 4])
demo([1, 2, 3, 4])
