list1=[["张飞",78,75],["李大刀",92,67],["李墨白",84,88],["王老虎",84,50],["雷小米",92,98]]
list2=sorted(list1,key=lambda x:(x[1],x[2]),reverse=True)
for i in range(len(list2)):
    for j in range(3):
        print(list2[i][j],end=" ")
    print("\n")