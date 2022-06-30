import re
def func1(num):
    return -1 if num<0 else str(bin(int(num))).count('1')
def func2(lst:list):
    count=0
    for i in range(len(lst)):
        for j in range(len(lst)):
            if lst[i]==lst[j] and i<j:
                count+=1
    return count
def func3(lst:list):
    d={str:3,float:2,int:1}
    return sorted(lst,key=lambda x:[d[type(x)],x],reverse=True)
#    return sorted(list(filter(lambda x:type(x)==type('s'),lst)),reverse=True)+sorted(list(filter(lambda x:type(x)==type(1.1),lst)),reverse=True)+sorted(list(filter(lambda x:type(x)==type(1),lst)),reverse=True)

def func4(s):
 f=re.compile(r'\w+')
 d={}
 for i in f.findall(s):
     if i not in d.keys():
         d[i]=1
     else:
         d[i]+=1
 return d
def func5(s,n):
    ans=[]
    for i in s:
        if '0'<=i<='9':
            ans.append(i)
        else:
            if 'a'<=i<='z':
                if ord(i)+n%10>ord('z'):
                    ans.append(chr(ord(i)+n%10-26))
                else:
                    ans.append(chr(ord(i)+n%10))
            else:
                if ord(i) + n % 10 > ord('Z'):
                    ans.append(chr(ord(i)+n%10-26))
                else:
                    ans.append(chr(ord(i)+n%10))
    return ''.join(ans)
def func6(s):
    f=re.compile(r'\d{3,4}-\d{7,8}')
    return f.findall(s)
def func7(lst:list):
    l=len(lst)
    m=lst[0][0]
    lst2=[[0 for i in range(l)] for j in range(l)]
    for i in range(l):
        m=min(m,lst[i][i])
    for i in range(l):
        for j in range(l):
            lst2[i][j]=lst[j][i]-m
    return lst2
def func8(lst:list):
    ans=[]
    for i in lst:
        flag=True
        for j in lst:
            if i[0]>=j[0] and i[1]>=j[1] and (i[0]>j[0] or i[1]>j[1]):
                flag=False
        if flag:
            ans.append(i)
    return sorted(ans,key=lambda x:x[0])

if __name__ == '__main__':
    print('1'*10)
    print(func1(6))
    print(func1(0))
    print(func1(15))
    print("2"*10)
    print(func2([1,2,3,1,1,3]))
    print(func2([1,1,1,1]))
    print(func2([1,2,3]))
    print('3'*10)
    print(func3(['python', 2.3, 3.7, 9, 3,'apple']))
    print(func3([3,'python', 1.1]))
    print('4'*10)
    print(func4('Happy I am happy are you happy'))
    print(func4(''))
    print('5'*10)
    print(func5('vw1122xyz', 4))
    print(func5('uvW1122xyz', 5))
    print(func5('abc1122def', 15))
    print('6'*10)
    print(func6('vw1122xyz 0512-1234567 abc 010-12345678'))
    print(func6('vw1122 0512-123456 abc 010-12345678 a'))
    print(func6(s = 'vw1122 0512-123 abc 01-12345678 a'))
    print(func6('vw1122 abc a'))
    print('7'*10)
    print(func7([[1,2,8],[4,5,9],[7,2,6]]))
    print(func7([[4, 5], [6, 7]]))
    print('8'*10)
    print(func8([(4, 2), (88, 21), (25, 27), (40, 72), (17, 33), (79, 14), (67, 66), (7, 18)]))
    print(func8([(5, 94), (68, 73), (77, 73), (21, 14), (30, 81), (43, 60), (73, 68), (84, 61)]))
    print(func8([(42, 11), (49, 46), (89, 33), (89, 96), (13, 1), (89, 11), (45, 39), (23, 5)]))
