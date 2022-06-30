import re
s=input("")
r=re.match(r'(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(\w{8,})',s)
if not r:
    print("False")
else:
    print("True")
