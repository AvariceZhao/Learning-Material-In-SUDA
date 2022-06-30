n=int(input(""))
count=0
while n>=15:
    if n>=75:
        count+=7*(n//75)
        n=n%75
    if n>=45 and n<75:
        count+=4*(n//45)
        n=n%45
    if n<45:
        count+=1*(n//15)
        n=n%15
print(count)