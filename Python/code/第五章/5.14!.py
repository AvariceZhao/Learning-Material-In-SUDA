import math
distance=[]
price=[]#坐到第几站需要的钱
ans=0
sumdistance=0
n=int(input(""))
if n<2:
    print("能坐0站")
else:
    price.append(0)
    price.append(2)
    for i in range(30):
        sumdistance+=distance[i]
        price.append(ceil(sumdistance/5))
        if price[i]>n:
            ans=i
            break
print(ans)



