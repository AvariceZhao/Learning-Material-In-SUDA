n=int(input("Please input the number of rows:"))
m=int(input("Please input the number of columns:"))
list1=[[0]*m]*n
list2=[[0]*m]*n

list3=[[0]*m]*n
for i in range(n):
    for j in range(m):
        list1[i][j]=int(input("Please input A[{},{}]:".format(i,j)))
for i in range(n):
    for j in range(m):
        list2[i][j]=int(input("Please input B[{},{}]:".format(i,j)))
for i in range(n):
    for j in range(m):
        list3[i][j]=list1[i][j]+list2[i][j]
print("C="+str(list3))


