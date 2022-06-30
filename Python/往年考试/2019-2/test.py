n=int(input())
print([m for m in range(2,n) if 0 not in (m%i for i in range(2,int(m**0.5)+1))])