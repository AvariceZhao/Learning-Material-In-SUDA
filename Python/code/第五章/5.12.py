import math
list1=["张三","李四","王五","赵六","孙七","周八","吴九"]
n=math.ceil(len(list1)/2)
print("分组    ",end="")
for i in range(1,n+1):
    print("{}     ".format(i),end="")
print("\n奇数组",end="  ")
for i in range(len(list1)):
    if i%2==0:
        print(list1[i],end="  ")
print("\n偶数组",end="  ")
for i in range(len(list1)):
    if i%2==1:
        print(list1[i],end="  ")
