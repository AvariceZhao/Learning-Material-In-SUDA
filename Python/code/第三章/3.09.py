list1=[]
for i in range(2,500):
    flag=True
    for j in range(2,int(i**0.5)+1):
        if i%j==0:
            flag=False
    if flag:
        list1.append(i)
count=0
for i in range(len(list1)):
    print(list1[i],end=" ")
    count+=1
    if count==5:
        print("\n")
        count=0

