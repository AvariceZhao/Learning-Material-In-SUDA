#序列解包

print("简单序列解包")

def demo1(a, b, c):
    print(a, b, c)

def demo2(**p):
    print(p)

demo1(*[1, 2, 3])
demo1(*(4, 5, 6))
demo1(*{4, 6, 5})  #??

print("字典键解包")
demo1(*{1: 2, 2: 4, 3: 6})

print("字典值解包")
demo1(**{"a": 2, "b": 4, "c": 6})

print("字典可变长参数")
demo2(a=2, b=4, c=6)