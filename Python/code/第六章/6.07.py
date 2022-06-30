d1={"a":5,"b":6,"c":7,"e":9}
d2={"b":7,"c":8,"d":9,"f":6}
l1=[]
l2=[]
l3=[]
l4=[]
for i in d1:
    l1.append(i)
    l2.append(d1[i])
for i in d2:
    l3.append(i)
    l4.append(d2[i])
for i in l2:
    if i in l4:
        print(l1[l2.index(i)],end=":")
        print(i,end="   ")
        print(l3[l4.index(i)], end=":")
        print(i, end="\n")
