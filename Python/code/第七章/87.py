def t(s:str,t):
    if t==1:
        for i in s:
            if 97<=ord(i)<=122:
                print(chr(ord(i)-32),end="")
            else:
                print(i,end="")
    elif t==2:
        for i in s:
            if 65<=ord(i)<=90:
                print(chr(ord(i)+32),end="")
            else:
                print(i,end="")
    else:
        print("your choice is false")
    return None


s=input("input a string")
mode=int(input("input your choice,input '1'or'2'"))
t(s,mode)
