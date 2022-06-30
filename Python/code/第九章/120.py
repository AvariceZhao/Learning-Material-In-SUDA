import re
check=re.compile('(\w+)')
with open('article.txt') as f:
    a=f.read()
s=set()
for i in check.findall(a):
    s.add(i)
s=list(s)
ans={}
for i in s:
    ans[len(i)]=[0,[]]
for i in s:
    ans[len(i)][0]+=1;
    ans[len(i)][1].append(i)
print(list(sorted(ans.items())))
for i in list(sorted(ans.items())):
    print("{}:{},".format(i[0],i[1][0]),end="")
    for j in i[1][1]:
        print(j,end=" ")
    print("\n")