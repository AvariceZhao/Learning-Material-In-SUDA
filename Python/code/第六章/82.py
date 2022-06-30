name=list(input("input all the names,names are devided by space,end with ENTER ").split(" "))
ids=list(input("input all the ids,ids are devided by space,end with ENTER ").split(" "))
person=[[0 for j in range(2)] for i in range(len(name))]
for i in range(len(name)):
    person[i][0]=name[i]
    person[i][1]=ids[i]
person.sort(key=lambda x:x[0])
for i in person:
    print("{} {}".format(i[0],i[1]))
person.sort(key=lambda x:x[1])
for i in person:
    print("{} {}".format(i[1],i[0]))