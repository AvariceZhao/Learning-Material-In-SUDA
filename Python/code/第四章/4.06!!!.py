import random
userlist=[["name1","password1"],["name2","password2"],["name3","password3"]]
for i in userlist:
    i.append(random.randint(1000,9999))
name=input("input your name password and key")
password=input("")
key=int(input(""))
flag=False
for i in range(len(userlist)):
    if name in userlist[i]:
        flag=True
        if password not in userlist[i]:
            print("用户名或密码不正确")
        else:
            if key not in userlist[i]:
                print("验证码不正确")
            else:
                print("登录成功")
if not flag:
    print("用户名或密码不正确")



