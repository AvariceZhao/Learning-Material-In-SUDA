import random
firstname=["f1","f2","f3","f4",'f5','f6']
lastname=['l1','l2','l3','l4','l5','l6']
d={}
l=[]
for i in range(12):

    for j in range(6):
        c = random.randint(0, 100)
        d[firstname[j]]=c
    for k in range(6):
        c = random.randint(0, 100)
        d[lastname[random.randint(0,5)]]=c
for m in d:
    l.append(m)
for i in l:
    if 0<=d[i]<=18:
        del d[i]
print(d)


