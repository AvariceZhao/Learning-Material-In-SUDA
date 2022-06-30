import random
s1=set()
s2=set()
while(len(s1)<=200):
    x=random.randint(0,500)
    s1.add(x)
while(len(s2)<=200):
    y=random.randint(0,500)
    s2.add(y)
same=s1&s2
different=s1^s2
x=0
for i in s1:
    x+=1
    if(x==10):
        print("%5d"%i)
        x=0
    else:
        print("%5d"%i,end="")
print("")
x=0
for j in s2:
    x+=1
    if(x==10):
        print("%5d"%j)
        x=0
    else:
        print("%5d"%j,end="")
