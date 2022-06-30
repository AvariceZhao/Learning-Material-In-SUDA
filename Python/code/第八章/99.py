address=list(input("input the IPv4 address").split('.'))
flag=True
for i in address:
    if int(i)>255 or int(i)<0:
        flag=False
    else:
        pass
if flag:
    if int(address[0])<=127:
        print("A类")
    elif 128<=int(address[0])<=191:
        print("B类")
    elif 192<=int(address[0])<=223:
        print("C类")
    elif 224<=int(address[0])<=239:
        print("D类")
    else:
        print("E类")
else:
    print("the IPv4 address you input is invalid")