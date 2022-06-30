s=input("")
n=len(s)
char=[" ",",",".","!","<",">","`","~","?","/"]
for i in range(len(s)-1):
	if s[i]in char and s[i+1]!=" ":
		s=s[:i+1]+" "+s[i+1:]
	else:
		continue
for i in list(s.split()):
	print(i,end=" ")