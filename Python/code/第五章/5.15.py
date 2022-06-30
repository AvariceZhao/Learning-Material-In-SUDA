n=int(input(""))
list1=[x for x in range(1,n+1)]
for i in range(1,n+1):
    print("   "+str(i),end="")
print("\n")
for i in range(1,n+1):
    print(i,end="  ")
    for j in range(1,i+1):
        print(i*j,end="  ")
    print("\n")