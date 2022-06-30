import random
n=random.randint(0,100)
print("n={}".format(n),end=" ")
if n%2==0:
    print("偶数")
else:
    print("奇数")