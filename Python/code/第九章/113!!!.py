import re
s=re.compile(r'^\s')
with open('article.txt','r',encoding='utf8') as f:
    lines=f.readlines()
l1=re.split('[.]',lines[0])
l2=[]
for i in l1:
    if i!=' ':
        l2.append(i[0].upper()+i[1::]+'.')
with open('new_article.txt','w+') as write:
    for i in l2:
        write.write(i+'\n')