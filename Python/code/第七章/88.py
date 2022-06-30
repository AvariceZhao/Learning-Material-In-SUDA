from math import sqrt
def DivisorSum(i:int):
    sum=0
    for j in range(1,int(sqrt(i)+3)):
        if i%j==0:
            sum+=j
    return sum
n=int(input(""))
print(DivisorSum(n))
