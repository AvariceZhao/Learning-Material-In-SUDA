import re
a=re.compile('(\w+)')
with open("Names.txt") as f:
    files=f.read()
s=a.findall(files)
s1=input("输入待插入的文本")
if s1 in s:
    print("名字已在文件中存在，不能插入")
else:
    s.append(s1)
    s.sort()
    with open("new_word.txt",'w+') as f2:
        for i in s:
            f2.write(i+'\n')