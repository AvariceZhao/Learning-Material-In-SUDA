num=int(input("input a num"))
count=0
list1=[]
while num/10!=0:
    list1.append(num%10)
    num=int(num/10)
    count+=1
print(count)
list1.reverse()
for i in list1:
    print(i,end=" ")
list1.reverse()
print("")
for i in list1:
    print(i,end="")
