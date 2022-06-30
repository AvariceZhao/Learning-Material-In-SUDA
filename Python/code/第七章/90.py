from math import sqrt
def prime(i:int):
    flag=True
    if i==1:
        flag=False
    for j in range(2,i):
        if i%j==0:
            flag=False
    return flag
def ReverseTest(s:str):
    if s=='1':
        return False
    l=[]
    for i in s:
        l.append(i)
    return l==l[::-1]

n=int(input(""))
if prime(n) and ReverseTest(str(n)):
    print("The number meets the requirement")
else:
    print("The number does not meet the requirement")
count=0
t=1
while count<30:
    t+=1
    if prime(t) and ReverseTest(str(t)) :
        count+=1
        print(t,end=" ")
