def f(a):
    if a==1 or a==2:
        return 1
    else:
        return f(a-1)+f(a-2)
n=int(input("input n"))
print(f(n))