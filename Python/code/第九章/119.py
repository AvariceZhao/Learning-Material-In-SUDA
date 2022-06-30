import re
check=re.compile('(\w+)')
l=['a','e','i','o','u','A','E','I','O','U']

with open('word.txt') as file:
    a=file.read()
ans=list(check.findall(a))
with open('new_word.txt','w+') as f:
    for i in ans:
        if i[0] in l:
            f.write(i+'\n')