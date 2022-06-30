import math

def func1(x):
    return sum([i for i in range(2,x+1) if 0 not in [i%j for j in range(2,int(i**0.5)+1)]])

def func2(x):
    return x==x[::-1]
    
def func3(n):
    return sum([i**4 for i in list(map(int,list(str(n))))])==n
    
def func4(lst,k):

    return(len([i for i in range(0,k) if lst[i]<lst[k]]),len([j for j in range(k+1,len(lst)) if lst[j]>lst[k]]))

def func5(r,lst):
    return len([1 for (i,j) in lst if math.sqrt(i**2+j**2)<r])

def func6(lst):
    return sorted(lst,key=lambda s:sum(list(map(ord,list(s))))/len(s),reverse=True)
        
def func7(s):
    return sum([i[0] for i in sorted(list(set(sorted([(i,s.count(i)) for i in s]))),key=lambda x:x[1])])

def func8(s1, s2):
    return None if  not set(s1)&set(s2) else sorted(list(set(s1)&set(s2)))

if __name__=="__main__":
    print(func1(11))
    print(func1(13))
    print('*'*100)
    print(func2('efNNfe'))
    print('*' * 100)
    print(func3(1634))
    print('*' * 100)
    print(func4([15,6,3,7,8],2))
    print(func4([1,2,3,4,5],4))
    print('*' * 100)
    print(func5(5,[(1,1.5), (6,7.5),(-1.5,-1.5)]))
    print('*' * 100)
    print(func6(['I','love','China']))
    print(func6(['is','OK']))
    print('*' * 100)
    print(func7([123,0,89,0,0,0,123,89,1,123]))
    print(func7([]))
    print(func7([1,1,1,1,1]))
    print('*' * 100)
    print(func8('China','Cap'))
    print(func8('abc','efg'))
    pass
