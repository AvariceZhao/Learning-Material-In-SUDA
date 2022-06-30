import copy
n=int(input("input n"))
l=[[0 for j in range(n)] for i in range(n)]
count=0
l[0][int((n-1)/2)]=1
count+=1
x=0
y=int((n-1)/2)
while count!=n*n:
    a=x             #a,b用于记录x,y在填写前的坐标，方便在目标位置有数后进行返回
    b=y
    x-=1
    y+=1
    if y>n-1:
        y=0
    if x<0:
        x=n-1

    if l[x][y]==0:
        count+=1
        l[x][y]=count
    else:
                x=a+1
                y=b

                if l[x][y]==0:
                    a=x
                    b=y
                    count+=1
                    l[x][y]=count
for i in l:
    for j in i:
        print(j,end=" ")
    print("\n")

