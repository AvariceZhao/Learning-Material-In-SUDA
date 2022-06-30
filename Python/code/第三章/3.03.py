import copy
l=input("input a list").split(",")
b=copy.deepcopy(l)
l.reverse()
flag=1
for i in range(len(b)):
    if l[i]!=b[i]:
        flag=0
if flag==1:
    print("yes")
else:
    print("no")