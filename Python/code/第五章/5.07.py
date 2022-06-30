list1=[0,0,0]
while(1):
    x=int(input(""))
    if x<=0:
        break
    elif x>=90:
        list1[0]+=1
    elif 60<=x<90:
        list1[1]+=1
    else:
        list1[2]+=1
print("优秀{}人，通过{}人，不及格{}人".format(list1[0],list1[1],list1[2]))