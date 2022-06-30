import random
list1=["+","-","*","/"]
num1=random.randint(1,100)
num2=random.randint(1,100)
t=random.randint(0,3)
char=list1[t]
print("{0}{1}{2}=".format(num1,char,num2))
if t==0:
    ans=num1+num2
elif t==1:
    ans=num1-num2
elif t==2:
    ans=num1*num2
else:
    ans=num1/num2
if ans==float(input("")):
    print("回答正确")
else:
    print("回答错误")



