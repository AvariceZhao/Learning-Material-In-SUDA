#关键参数 -> 缺省参数

def demo(a, b, c = 0):
    print(a)
    print(b)
    print(c)
    print("-" * 40)
    return

demo(9, c = 5, b = [1, 2, 3, 4])
demo(9, b = [1, 2, 3, 4])
demo(b = [1, 2, 3, 4], a = 9)
#demo(9, c = [1, 2, 3, 4])
