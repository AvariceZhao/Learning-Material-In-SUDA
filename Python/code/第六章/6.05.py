n=input("")
d={}
l1=[]
while(65<=ord(n)<=90):
    d[n]=0
    l1.append(n)
    n = input("")
for i in l1:
    d[i]+=1
print(d)