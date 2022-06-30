import copy
n=int(input("input n"))
l=[[0 for j in range(n)] for i in range(n)]
count=0
l[0][int((n-1)/2)]=1
count+=1
x=0
y=int((n-1)/2)
while count!=n*n:
    a=x-1
    b=y+1
    if a < 0:
        a = 4
    if a > 4:
        a = 0
    if b < 0:
        b = 4
    if b > 4:
        b = 0
    if 0<=a<=4 and 0<=b<=4 and l[a][b]==0:
        count+=1
        l[a][b]=count
        print("a={} b={}({})".format(a, b, l[a][b]))
        print(l)
        x=a
        y=b
    if 0<=a<=4 and 0<=b<=4 and l[a][b]!=0:
        a=x
        b=y
        if a<=3 and l[a+1][b]==0:
            count+=1
            print("a={} b={}({})".format(a, b, l[a][b]))
            print(l)
            l[a + 1][b] =count
print(l)

