l=list(input("input a list"))
n=len(l)
sorted(l)
if n%2==0:
    midnum=l[int(n/2-1)]
else:
    midnum=l[int((n+1)/2-1)]
print(midnum)