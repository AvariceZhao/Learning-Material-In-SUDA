d={}
for i in range(26):
    d[chr(i+65)]=i+10
for j in range(26):
    d[chr(j+97)]=j+26
for k in range(10):
    d[str(k)]=chr(k+97)
s=input("input a string")
length=len(s)
for c in s:
 print(d[c],end=" ")


