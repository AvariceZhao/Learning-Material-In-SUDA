import cmath
num1=int(input(""))
a=int(num1%10)
b=int((num1/10)%10)
c=int(num1//100)
ans=a+b+c
print("%4d"%ans)