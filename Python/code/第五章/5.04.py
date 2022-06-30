char=input("")
if char>='A'and char<='Z':
    print(chr(ord(char)+32))
elif char>='a'and char<='z':
    print((chr(ord(char)-32)))
else:
    print(char)
