n=input("input a string")
l=[]
for i in n:
    if i!=',' and i!='.' and i!='!' and i!=' ':
        l.append(i)
n="".join(l)
n=n.lower()
if n==n[::-1]:
    print(True)
else:
    print(False)
