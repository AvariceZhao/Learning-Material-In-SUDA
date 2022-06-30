flag=False
while(not flag):
    a = input("输入一个10-50之间的整数")
    try:
        a=int(a)
        if not (10<=a<=50):
            print("范围不符，重新输入")
            continue
        flag=True
        print("输入成功")
    except (ValueError,TypeError):
        a=input("类型不符,请重新输入")

