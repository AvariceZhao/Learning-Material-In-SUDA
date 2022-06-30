list0=input("input numbers divided by ',").split(",")
list1=[]
for i in list0:
    list1.append(int(i))#将字符列表list0转为数字列表list1
list2=[]#储存质数
list3=[]#计算所有可能的质数组合
ans=0
for k in list1:
    flag=True
    if k == 1:
        flag=False
    for i in range(2,int(k**0.5+1)):
             if k%i==0 :
               flag=False
    if k in list2:
        flag=False
    if flag :
        list2.append(k)
for i in range(len(list2)):
    for j in range(i+1,len(list2)):
        list3.append(list2[i]+list2[j])
for i in list2:
    if i in list3:
        ans+=1
print(ans)




