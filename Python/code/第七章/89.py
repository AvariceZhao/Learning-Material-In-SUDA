def NumReverse(i:int):
    while i>=1:
        print(int(i%10),end="")
        i/=10
    return None
n=int(input("input n"))
NumReverse(n)