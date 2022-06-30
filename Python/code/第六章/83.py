import random
n=int(input("input N"))
l=[]
l1=[]
for i in range(n):
    l.append(random.randint(1,1000))
for i in l:
    if not i in l1:
        l1.append(i)
l1.sort()
print(l1)