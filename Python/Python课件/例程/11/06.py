#关键参数 -> 普通参数

def demo(a, b, c):
    print(a)
    print(b)
    print(c)
    print("-" * 40)
    return

demo(9, c = 5, b = [1, 2, 3, 4])
demo(c = 100, b = [1, 2, 3, 4], a = 5)
demo(c = 100, b = [1, 2, 3, 4], a = 5)
