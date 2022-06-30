import random
a=random.randint(0,9)
n=int(input(""))
sum=0
for i in range(1,n+1):
    sum+=a*(10**(i-1))*(n-i+1)
for i in range(1,n+1):
    if(i!=n):
        print(str(a)*i+"+",end="")
    else:
        print(str(a)*i+"="+str(sum))
