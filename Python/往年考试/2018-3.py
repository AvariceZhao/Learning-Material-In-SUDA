import re
def func1(y,m,d):
    l=[31,28,31.30,31,30,31,31,30,31,30,31]
    if y%400==0 or(y%4==0 and y%100!=0):
        l[1]=29
    if not(1<=m<=12 and 1<=d<=l[m-1]):
        return -1
    else:
        return sum(l[:m-1:])+d
def func2(h,f):
    for i in range(h+1):
        if i*2+(h-i)*4==f:
            return i,h-i
    return None
def func3(lst):
    return None if len(lst)==1 else sum(lst)==(sorted(lst)[0]+sorted(lst)[-1])*len(lst)/2
def func4(lst):

    for i in lst :
        if type(i)!=type(1):
            return None
    return sorted(lst)[int((len(sorted(lst))+1)/2)-1] if len(lst)%2==1 else int((sorted(lst)[int(len(lst)/2)]+sorted(lst)[int(len(lst)/2)-1])/2)
def func5(s):
    s1=s.lower()
    l=list(s1.split(' '))
    d={'zero':'0','one':'1','two':'2','three':'3','four':'4',"five":'5','six':'6','seven':'7','eight':'8','nine':'9','ten':'10'}
    ans=''
    for i in l:
        ans+=d[i]
    return ans
def func6(a,b,c,d):
    s=set()
    for x in range(a,b+1):
        for y in range(c,d+1):
            s.add(x/y)
    return len(s)
def func7(s1,s2,n):
    if len(s1)%n!=0:
        s=s1+(n-len(s1)%n)*' '
    else:
        s=s1
    ans=''
    for i in range(int(len(s)/n)):
        ans+=s[i*n:i*n+n]+s2
    return ans
def func8(s1):
    l=[]
    l.append(s1)
    find=re.compile(r'(<\w+>)')
    f=find.findall(s1)
    for i in f:
        l.append(i.upper()[1:-1])
        l.append(l[len(l)-2].replace(i,'['+l[len(l)-1]+'-'+str(len(i)-2)+']'))
    return l[len(l)-1]
if __name__ == '__main__':
    print("1"*10)
    print(func1(2019,1,32))
    print(func1(2019,3,1))
    print('2'*10)
    print(func2(35,110))
    print(func2(35,111))
    print(func2(0,0))
    print(func2(100,100))
    print('3'*10)
    print(func3([1]))
    print(func3([19, 1]))
    print(func3([19, -1, 100]))
    print(func3([33, -7, 3, 13, 43, 53, 23]))
    print('4'*10)
    print(func4([19, -1, 100]))
    print(func4([19, -1, 1000, 101]))
    print('5'*10)
    print(func5("one one two two three three four"))
    print(func5("One One Zero"))
    print(func5("Nine one one"))
    print('6'*10)
    print(func6(1,10,1,1))
    print(func6(1, 10, 1, 10))
    print(func6(10, 10, 1, 10,))
    print('7'*10)
    print(func7('abcd','#',1))
    print(func7('abcd', '##',2))
    print(func7('abcd','##',3))
    print(func7('abcd','##',5))
    print('8'*10)
    print(func8("President <4t>"))
    print(func8("hello world"))
    print(func8("he defended <_abc>, his decision to <43>"))