import re
f=open('data.txt','rt')
l=f.read()
f.close()
lst=re.findall(r"\d+",l)
print(l)
data_set={int(x) for x in lst if '3' not in x and '5' not in x}
print(data_set)
for i in data_set:
    print(i)