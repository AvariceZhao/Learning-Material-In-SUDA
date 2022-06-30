import re
s=input("")
k=input("")
judge=re.compile(r"(\w{"+k+r"}).*?\1.*")
if judge.findall(s):
    print(True)
else:
    print(False)