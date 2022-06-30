d={}
s=input("input a string")
for i in s:
    d[i]=0
for i in s:
    d[i]+=1
for i in s:
    print("{}:{},".format(i,d[i]),end="")