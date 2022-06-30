import random
import functools
def maxx(x,y):
    return max(x,y)
def odd(x):
    return True if x%2==0 else False
f=lambda x:x+1
l=[i for i in range(10)]
#print(l,random.shuffle(l),l,list(map(f,l)))
#print(functools.reduce(maxx,l))
print(list(filter(odd,l)))