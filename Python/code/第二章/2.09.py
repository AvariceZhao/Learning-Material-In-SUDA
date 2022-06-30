import random
num=random.randint(100,999)
print(num)
a=num//100
b=int(num/10)%10
c=num%10
print(c*100+b*10+a)