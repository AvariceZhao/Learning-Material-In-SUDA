def f(a):
    if a==1 or a==2:
        return 1
    else:
        if l[a]!=0:
            return l[a]
        else:
            l[a]=f(a-1)+f(a-2)
        return l[a]
l=[]
n=int(input())
for i in range(n+1):
    l.append(0)
# k=1
# for i in range(1,n):
#     print(f(k),' ')
#     k+=1
print(f(100))