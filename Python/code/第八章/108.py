import re
u=re.compile(r'\D[a-zA-Z0-9-]{5,}')
p=re.compile(r'(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])\w{6,}')
username = input("input your username")
while not u.findall(username):
    username = input("your username is invalid,input it again")
password=input("input your password")
while not p.findall(password):
    password=input("your password is invalid,input it again")
confirmpassword=input("input your password again to confirm it")
while confirmpassword!=password:
    confirmpassword=input("the confirmpassword is not same as password,input it again")
print("Your have registered your account number")

