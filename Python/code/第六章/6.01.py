a=(65.5,70.2,100.5,45.5,88.8,55.5,73.5,67.8)
sum=0
sum1=0
for i in a:
     sum+=i
ave=sum/len(a)
for i in a:
    sum1+=(ave-i)**2
print(sum1/len(a))