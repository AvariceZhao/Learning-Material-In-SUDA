def BUbbleSort(l:list):
    for i in range(len(l)):
        for j in range(i,len(l)):
            if l[j]<=l[i]:
                l[j],l[i]=l[i],l[j]
    for k in l:
        print(k,end=" ")
def ReverseBUbbleSort(l:list):
    for i in range(len(l)):
        for j in range(i,len(l)):
            if l[j]>=l[i]:
                l[j],l[i]=l[i],l[j]
    for k in l:
        print(k,end=" ")
l=[]
for i in range(10):
    x=int(input())
    l.append(x)
BUbbleSort(l)
print("")
ReverseBUbbleSort(l)