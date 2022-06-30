name=('n1','n2','n3','n4','n5','n6','n7','n8','n9')
age=(12,34,45,56,12,34,42,45,13)
name1=list(name)
age1=list(age)
d={}
for i in range(len(name)):
    d[name1[i]]=age[i]
print(d)