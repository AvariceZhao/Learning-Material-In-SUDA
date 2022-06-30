import re
s=re.compile(r'^\s')
s1=' '
s2=' 1'
s3='2 '
print(s.findall(s1),s.findall(s2),s.findall(s3))
if s.findall(s3):
    print(1)