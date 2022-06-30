n=float(input("Please input the number of numbers:"))
sum=0
count=0
if n%1!=0:
    print("error number,please input a integer ")
    n = float(input("Please input the number of numbers:"))
    while n!=0 and count<n:
        count+=1
        sum+=int(input("Pleas input number"+str(count)+":"))
    print(sum)
else:
    while n!=0 and count<n:
        count+=1
        sum+=int(input("Pleas input number"+str(count)+":"))
    print(sum)