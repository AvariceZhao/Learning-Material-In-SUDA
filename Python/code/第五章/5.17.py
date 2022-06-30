n=int(input("please input a number "))
flag=True
for i in range(2,n+1):
    flag = True
    for j in range(2,i):

        if i%j==0:
            flag=False
    if flag:
        print(i)
