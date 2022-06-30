import re
def func1(x,y):
    if (-1<=x<=1 and (y==1 or y==-1)) or (-1<=y<=1 and (x==1 or x==-1)):
        return 0
    elif -1<x<1 and -1<y<1:
        return 1
    else :
        return -1

def func2(d,l,r):
    return None if not (0<=d<=9 or l>=r) else sum([str(i).count(str(d)) for i in range(l,r+1)])
def func3(lst):
    replace=[]
    ans=[]
    for i in lst:
        replace.append(int(str(i)[0]))
        replace.append(int(str(i)[-1]))
    prime=[i for i in range(2,max(replace)+1) if 0 not in [i%j for j in range(2,int(i**0.5)+1)]]
    h=0
    s=''
    for i in replace:
        if i not in prime:
            s+=str(i)
        else:
            if s!='':
                ans.append(int(s))
                s=''
                ans.append(i)
            else:
                ans.append(i)
    if s!='':
        ans.append(int(s))
    return ans
def func4(lst):
    d={}
    for i in range(len(lst)):
        for j in range(len(lst)):
            d[i+j]=[]
    for i in range(len(lst)):
        for j in range(len(lst)):
            d[i+j].append(lst[i][j])
    ans=list(d.values())
    for i in range(len(ans)):
        if len(ans[i])<3:
            for k in range(3-len(ans[i])):
                ans[i].append(0)
        ans[i].sort(reverse=True)
    return ans
def func5(s):
    return s[0].upper()+s[1::].lower() if 'A'<=min(s)<='Z'else s[0].upper()+s[1:-1:].lower()+s[-1].upper()
def func6(s1):
    f=re.compile(r'\w+')
    word=f.findall(s1)
    ans=[]
    a=''
    for i in word:
        if len(i)<=5:
            a=i
            ans.append(a)
        else:
            a=i[0]+'*'*(len(i)-2)+i[-1]
            ans.append(a)
    return ' '.join(ans)
def func7(lst,s):
    return sum([1 for i in lst if len(set(i)&set(s))==len(set(i))])
def func8(lst):
    ans=[]
    d={}
    for i in lst:
        if len([1 for j in i[0] if '0'<=j<='9'])==len(i[0]) and len(i[0])==9 and 1<=int(i[1])<=3:
            ans.append(i)
    for i in ans:
        d[i[0]]=0
    for i in ans:
        d[i[0]]+=i[1]
    return sorted(list(d.items()),key=lambda i:[-int(i[1]),int(i[0])])[0]
if __name__ == '__main__':
    print('*'+'1'+'*')
    print(func1(0, 0))
    print(func1(1, 0))
    print(func1(2, 2))
    print('*'+'2'+'*')
    print(func2(0, 0,11))
    print(func2(1,3, 4))
    print(func2(1,4,4))
    print(func2(12,3,6))
    print('*' + '3' + '*')
    print(func3([1, 234, 5, 6, 70, 890]))
    print(func3([12, 34, 56, 78, 90]))
    print(func3([123]))
    print('*'+'4'+'*')
    print(func4([[1,2,3], [4,5,6], [7,8,9]]))
    print('*' + '5' + '*')
    print(func5("wE"))
    print(func5("comPUtER"))
    print(func5('university'))
    print('*' + '6' + '*')
    print(func6("hello ! world.,Computer. class,54,5w"))
    print(func6("one two:::three, FOUR.., five"))
    print(func6('worldcomputer'))
    print(func6('"!=-,."'))
    print('*' + '7' + '*')
    print(func7(["cat","bt","hat","tree"],"atach"))
    print(func7(["hello","world","soochow"],"welldonehoneyr"))
    print('*' + '8' + '*')
    print(func8([('192740506',3),('192740101',2),('192740101',2)]))
    print(func8([('192740506',3),('192740A01',2),('192740101',3)]))
    print(func8([('19274056',3),('192740A01',2),('192740101',3)]))


