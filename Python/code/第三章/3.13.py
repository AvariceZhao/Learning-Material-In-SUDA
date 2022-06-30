list1=[["张飞",78,75],["李大刀",92,67],["李墨白",84,88],["王老虎",50,50],["雷小米",99,98]]
def scoresort(stu):
    return stu[1]+stu[2]
list1.sort(key=scoresort,reverse=True)
for i in list1:
    print(i[0],end=" ")
    print(i[1]+i[2])

