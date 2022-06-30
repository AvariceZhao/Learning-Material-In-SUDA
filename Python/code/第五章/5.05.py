x=input("")
count=0
sum=0
for i in range(len(x)):
    sum+=int(x[i])
    if x[i]=='0':
        count+=1
print("共有{}个0，所有数字之和为{}".format(count,sum))