s=input("input a string")
l1=[]#存字符
l1.append(s[0])#存数量
l2=[1]
count=0#存当前处理字符在l2中对应的索引
for i in range(1,len(s)):
    if s[i-1]==s[i]:
        l2[count]+=1
    else:
        l1.append(s[i])
        count+=1
        l2.append(0)
        l2[count]+=1
for i in range(len(l1)):
    print("{}{}".format(l1[i],l2[i]),end="")


