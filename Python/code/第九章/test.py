f=open("text.txt","rt")
lines=f.readlines()
f.close()
print(lines)
total=0
count=0
for item in lines:
    t=int(item)
    total+=t
    count+=1
print(total,count)