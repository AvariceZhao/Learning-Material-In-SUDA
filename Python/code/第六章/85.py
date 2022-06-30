import random
import sys

A=set()
B=set()
while(len(A)<100):
    x=str(random.randint(0,1000))
    A.add(x)
while(len(B)<100):
    x=str(random.randint(0,1000))
    B.add(x)
x=0
for j in A:
    x+=1
    if(x==10):
        print("%5s"%j)
        x=0
    else:
        print("%5s"%j,end="")
print("")
x=0
for i in B:
    x+=1
    if(x==10):
        print("%5s"%i)
        x=0
    else:
        print("%5s"%i,end="")

same=A&B
all=A|B
x=0
print("")
while(x<3):
    input1=set(input("input A|B,numbers are devided by space,end with ENTER").split(" "))
    input2=set(input("input A&B,numbers are devided by space,end with ENTER").split(" "))
    if(input1==all and input2==same):
        print("Your answer is true")
        sys.exit()
    else:
        print("Your answer is wrong,please input again")
        x+=1
print("A|B is:",end="")
for i in all:
    print(i,end=" ")
print("")
print("A&B is:",end="")
for j in same:
    print(j,end=" ")