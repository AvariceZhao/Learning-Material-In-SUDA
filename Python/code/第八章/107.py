import re
phone=re.compile(r'1\w{10}')
tele=re.compile(r'0\w{2,3}-?[0-9][1-9]{6,7}')
special=re.compile(r'\w{2,4}$')
n=input("input a string")
if phone.findall(n):
    print("是手机号码")
elif tele.findall(n):
    print("是国内固定电话号码")
elif special.findall(n):
    print("是特殊号码")
else:
    print("不是电话号码")
