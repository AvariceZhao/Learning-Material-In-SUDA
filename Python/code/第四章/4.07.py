import random
num=random.randint(0,100)
t=-1
print("input a number")
while t!=num:
    t=int(input(""))
    if t>=0 and t<=100:
        if t>num:
            print("大了")
        elif t<num:
            print("小了")
        else:
            print("恭喜，猜正确了")
    else:
        print("输入错误")