import re
a=re.compile('(-?[0-9]+)')
ans=[]
with open('StrInts.txt','r') as file:
    origin=file.read()
s=a.findall(origin)
for i in s:
    flag=True
    for j in range(len(i)):
        if(i[0]!='-'):
            if j%2==1 and int(i[j])%2==0 :#是否有负号对偶数位对应的j有影响
                flag=False
                break
        else:
            if j!=0 and j%2==0 and int(i[j])%2==0 :#排除‘-’
                flag=False
                break
    if flag:
        ans.append(i)
f=open('StrInts.txt','w+')
count=0
for i in ans:
   f.write('{:' '>8}'.format(i))
   count+=1
   if count==3:
       f.write('\n')
       count=0