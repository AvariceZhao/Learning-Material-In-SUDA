#函数做返回值

def demo1():

    def demo1_1():
        print("demo1_1")
        return

    print("demo1")
    #print("id(demo1_1) =", id(demo1_1))
    demo1_1()

    return demo1_1()

f = lambda x:demo1()
# demo1_1()
f()
print("id(f) = ", id(f))
