import random
import copy
list1=[[],[],[],[]]

for i in range(4):
    for j in range(4):
        x=random.randint(0,100)
        list1[i].append(x)
list2=copy.deepcopy(list1)
for i in range(4):
    for j in range(4):
        list2[i][j]=list1[j][i]
list1=list2
for i in range(4):
    for j in range(4):
        print(list1[i][j],end=" ")
    print("")
