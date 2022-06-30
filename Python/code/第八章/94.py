def f(s:str):
    if len(s) < 2:
        return ""
    else:
        return s[:2]+s[len(s)-2:len(s)]
s=input("input a string")
print(f(s))
