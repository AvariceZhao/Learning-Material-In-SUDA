with open('config.txt','r') as file:
    f=file.readlines()
b=[]
ans=[]
for i in f:
    b.append(i.replace('\n',''))
for j in b:
    ans.append(list(j.split(':')))
with open('new_config.txt','w+') as f1:
    for k in ans:
        f1.write('<'+k[0]+'>'+k[1]+'</'+k[0]+'>\n')