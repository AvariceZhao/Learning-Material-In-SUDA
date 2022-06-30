#关键参数 -> 可变长参数

def demo(a, *b):
    print(a)
    print(b)
    print("-" * 40)
    return

demo(5, 6, 7)
#demo(5, b = (6, 7))
