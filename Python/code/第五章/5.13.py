money=int(input(""))
count=0
while(money>=1):
    if count<=10:
        money-=2
        count+=1
    elif 10<count<=20:
        money-=2*0.95
        count+=1
    elif 20<count<=50:
        money-=2*0.8
        count+=1
    else:
        money-=1
        count+=1
print(count)