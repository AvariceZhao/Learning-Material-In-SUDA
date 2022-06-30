import random
rnd=random.randint(100,200)
numberLst=[]
number26Lst=[]
for i in range(rnd):
    x=random.randint(100,500)
    numberLst.append(x)
    if '2' in str(x) or '6' in str(x):
        number26Lst.append(x)
count=0
for i in range(len(number26Lst)):
    print('{:>5}'.format(number26Lst[i]),end='')
    count+=1
    if count%8==0:
        print('')
resultLst=[]
for i in number26Lst:
    for j in range(2,i-1):
        if i%j==0:
            resultLst.append(j)
print(resultLst)
d={i:resultLst.count(i) for i in resultLst}
l=sorted(d.items(),key=lambda x:-x[1])
for i in range(5):
    print(l[i])
new=set(numberLst)
print(new)