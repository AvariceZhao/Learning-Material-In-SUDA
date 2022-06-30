n=input()
l=[]
for i in n:
    l.append(i)
l1=list(reversed(l))
flag=True
for i in range(len(l)):
    if l[i]!=l1[i]:
        flag=False
if flag:
    print(True)
else:
    print(False)