l=[1,3,4,6,6,7,8,8,10,21,22,22]
for i in range(len(l)-1):
    if l[i]>10:
        del l[i]
        i-=1
for i in range(len(l)-1):
     if l.count(l[i])>1:
        del l[i]
        i-=1
print(l)