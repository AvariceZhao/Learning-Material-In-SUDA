def func1(a):
    lst=[a%d for d in range(2,a-1)]
    return False if 0 in lst else True
n=int(input(""))
print(func1(n))