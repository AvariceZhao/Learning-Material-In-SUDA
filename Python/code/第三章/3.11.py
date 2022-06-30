str1=input("input two strings")
str2=input()
list1=[]
list2=[]
flag=(len(list1)==len(list2))
if  flag:
    for i in range(len(str1)):
        list1.append(str1[i])
    for i in range(len(str2)):
        list2.append(str2[i])
    list1.sort()
    list2.sort()

    for i in range(len(list1)):
        if list1[i]!=list2[i]:
            flag=False
else:
    print("NO")
if flag:
    print("YES")
else:
    print("NO")


