d={'name1':12,"name2":34,"name0":1,'name3':999,'name4':678,'name5':556,'name6':0.1}
l=[[0 for j in range(3)] for i in range(len(d))]
count=0
for i in d:
    l[count][0]=i
    l[count][1]=d[i]
    count+=1
l.sort(key=lambda x:x[0])
count=1
for i in l:
    print("{} {} {}".format(count,i[0],i[1]))
    count+=1
n=int(input(""))
sum=0
while n:
    sum+=l[n-1][1]
    l[n-1][2]+=1
    n=int(input(""))
for i in l:
    if i[2]!=0:
        print("名称：{} 单价：{} 数量：{} 小计金额：{}".format(i[0],i[1],i[2],i[2]*i[1]))
print("总额：{}".format(sum))