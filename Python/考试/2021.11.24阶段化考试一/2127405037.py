#  学号:2127405037
#  姓名:赵鹏
#  IP:192.168.157.16
#  上传时间:2021/11/24 19:28:23

import math

def func1(a,b):
    if a<=0 or b<=0:
        return False
    if a>b:
        if a%b!=0:
            return True
        else:
            return False
    elif a==b:
            return True
    else:
        if b%a!=0:
            return True
        else:
            return False
    pass

def func2(num):
    l=len(str(num))
    if l%2==0:
        return False
    else:
        return int(str(num)[int((l+1)/2)-1])
    pass

def func3(n):
    count=0
    count+=8*(n//50)
    n=n%50
    count+=4*(n//30)
    n=n%30
    count+=n//10
    return count
    pass

def func4(r,x,y):
    if x<=0 or y<=0 or r<=0:
        return False
    else:
            if x**2+y**2==r**2:
                return 2
            elif x**2+y**2<r**2:
                return 1
            else:
                return 3
    pass

def func5(n,m):
    if m<=0 or n<=0:
        return None
    count=0
    if n>=m:
        for i in range(m,n+1):
            l=[]
            for j in str(i):
                l.append(j)
            l.reverse()
            t=[]
            for i in l:
                t.append(i)
            l.reverse()
            flag=True
            for i in range(len(l)):
                if t[i]!=l[i]:
                    flag=False
            if flag:
                count+=1
    else:
        for i in range(n,m+1):
            l=[]
            for j in str(i):
                l.append(j)
            t = []
            for i in l:
                t.append(i)
            l.reverse()
            flag = True
            for i in range(len(l)):
                if t[i] != l[i]:
                    flag = False
            if flag:
                count += 1
    return count
    pass

def func6(n):
    if n<=0:
        return None
    ans=1
    for i in range(1,n+1):
        ans*=i
    l=[]
    for i in str(ans):
        l.append(i)
    count=0
    i=len(l)-1
    while(l[i]=='0'):
        count+=1
        i-=1
    return count
    pass

def func7(lst):
    j=[]
    o=[]
    for i in lst:
        if i%2==1:
            j.append(i)
        else:
            o.append(i)
    j.sort()
    o.sort(reverse=True)
    return j+o
    pass

def func8(lst):
    d={}
    for i in lst:
        d[i]=0
    for i in lst:
        d[i]+=1
    maxx=max(d.values())
    l=[]
    for i in d:
        if d[i]==maxx:
            l.append(i)
    l.sort(reverse=True)
    if len(l)==1:
        return l[0]
    else:
        return l
    pass

if __name__=="__main__":
    print(func1(1,1))
    print("-----"*100)
    print(func2(5555))
    print("-----" * 100)
    print(func3(80))
    print("-----" * 100)
    print(func4(5.0,3,4))
    print("-----" * 100)
    print(func5(100,101),end="                   5")
    print("-----" * 100)
    print(func6(36))
    print(func7([]))
    print("-----" * 100)
    print(func8([]))
    pass
