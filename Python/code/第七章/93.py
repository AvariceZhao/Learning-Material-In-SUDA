def findmax(l:list,a:int,b:int):
    mmax=-1
    p=-1
    for i in range(a,b):
        if l[i]>=mmax:
            mmax=l[i]
            p=i
    return p


def findmin(l:list,a:int,b:int):
    mmin=9999
    t=-1
    for i in range(a,b):
        if l[i]<=mmin:
            mmin=l[i]
            t=i
    return t


def SelectSort(l:list):
    for i in range(len(l)):
        l[i],l[findmin(l,i,len(l))]=l[findmin(l,i,len(l))],l[i]
    for j in l:
        print(chr(j),end=" ")
    return None
def SelectSort1(l:list):
    for i in range(len(l)):
        l[i],l[findmax(l,i,len(l))]=l[findmax(l,i,len(l))],l[i]
    for m in l:
        print(chr(m),end=" ")
    return None



l=list(map(str,input("输入10个字符，以空格分开").split(" ")))
for i in range(len(l)):
    l[i]=ord(l[i])
SelectSort(l)
print("")
SelectSort1(l)
