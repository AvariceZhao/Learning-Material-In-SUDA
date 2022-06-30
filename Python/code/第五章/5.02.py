x=input("")
n=int(x,16)
list1=[]
while n>0:
    list1.append(n%2)
    n=int((n-n%2)/2)
list1=list1[::-1]
for i in list1:
    print(i,end="")