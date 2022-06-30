s=input("input a string and a set of characters")
c=input("")
for i in s:
    if c.find(i)==-1:
        print(i,end="")
    else:
        pass