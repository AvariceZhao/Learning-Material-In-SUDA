import random
n=int(input())
h=100
s=0
last=0
for i in range(n):
    if i==0:
        s+=h
    else:
        last=0.5**i*h
        s+=last*2
print(s,last)