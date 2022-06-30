l=[1,3,4,6,6,7,8,8,10,21,22,22]
n=len(list(set(l)))
t=0
for i in range(len(l)-n):
    for j in l:
        if l.count(j)>1:
            del l[l.index(j)]
            break
for i in l:
    if i>=10:
        t+=1
for i in range(t):
    for j in l:
        if j>=10:
            del l[l.index(j)]
            break
print(l)

