f=open('Numbers.txt','r')
con=list(map(float,f.readlines()))
con.sort()
l=len(con)
s=sum(con)
ave=s/l
d=0
for i in con:
    d+=(i-ave)**2
d/=l
con.append(ave)
con.append(d)
f1=open('Sort.txt','w+')
for i in con:
    f1.write(str(i)+'\n')
f.close()