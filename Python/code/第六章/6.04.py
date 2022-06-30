a={"name1":[1,2,3,4,5,6,7],"name2":[2,2,3,5,5,6,8]}
l1=[]
for i in a:
    l1=a[i]
    l1.sort()
    del l1[0]
    del l1[5]
    sum1=0
    for j in l1:
        sum1+=j
    ave=sum1/len(l1)
    print("name={},score={:.1f}".format(i,ave))