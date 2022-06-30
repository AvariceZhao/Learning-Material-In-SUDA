g = lambda x:sorted(x,key=lambda y:y%10)
a=[i for i in range(0,20)]
b=g(a)
print(list(reversed(b)))
