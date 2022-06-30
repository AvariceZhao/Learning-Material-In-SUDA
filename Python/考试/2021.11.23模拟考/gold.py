import math

def func1(x):
    if x>=0:
        y = 5*x
    else:
        y = 3*abs(x)+1
    return y


def func2(x):
    if x>=10:
        y = 10
    elif x>=8 and x < 10:
        y = 8*(x**3)
    elif x>=3 and x< 8:
        y = 3*(x**2)
    elif x>=0 and x<3:
        y = x+1
    else:
        y = abs(x)

    return y
    
def func3(m,n):

    if m>n:
        return None
    sum=0
    for i in range(m,n+1):
        sum=sum+(i if i%2==1 else 0)
    return sum
    
def func4(m,n):

    count=0
    for i in range(m,n+1):
        if i<=0:
            continue;
        temp=i
        while temp:
            if temp%10==2: count+=1
            temp=temp//10
    return count   
    
def func5(Num):
    if Num<=0:
        return None
    res=[]
    temp=[int(i) for i in str(Num)]
    res.append(len(temp))
    res.append(sum(temp))
    res.append(max(temp))
    return res

def func6(m,n):
    if m<=0 or n<=0:
        return None
    if m<100:
        return m
    temp=[int(i) for i in str(m)]
    temp[0] = (temp[0]+n)%10
    res=int(''.join(list(map(str, temp))))
    return res
    

    
def func7(k, lst):
    lst[:k] = lst[k-1::-1]
    return lst

def func8(v, lst):
    L = [i for i in lst if density(i) >= v]
    L.sort(reverse = True)
    return L

def density(n):
    L = [ord(c) - ord('0') for c in str(n)]
    return sum(L) / len(L)    

if __name__=="__main__":
    pass
