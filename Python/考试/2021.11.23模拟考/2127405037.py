#  学号:2127405037
#  姓名:赵鹏
#  IP:192.168.157.30
#  上传时间:2021/11/22 14:58:09
# 赵鹏同学，你好：
#
# 下面是你本次模拟考试的成绩。
# 总分：83.5分，其中：
# 编程题第1题：10分
# 编程题第2题：10分
# 编程题第3题：10分
# 编程题第4题：7分
# 编程题第5题：15分
# 编程题第6题：10.5分
# 编程题第7题：15分
# 编程题第8题：6分
# 备注：
#
# 附件是你提交的程序源文件。
# 
# 赵雷
# 2021-11-23

import math

def func1(x):
    ans=0
    if x>=0:
        ans=5*x
    else:
        ans=x*(-3)+1
    return ans

def func2(x):
    if x>=10:
        y=10
    elif 8<=x<10:
        y=8*(x**3)
    elif 3<=x<8:
        y=3*(x**2)
    elif 0<=x<3:
        y=x+1
    else:
        y=-x

    return y
    
def func3(m,n):
    if m>n:
        return None
    else:
        sum=0
        for i in range(m,n+1):
            if i%2==1:
                sum+=i

        return sum
    
def func4(m,n):
    sum = 0
    for i in range(m,n+1):
            sum+=str(i).count('2')
    return sum

def func5(num):
    if num<=0:
        return None
    else:
        ans=[]
        s=str(num)
        ans.append(len(s))
        sum=0
        maxx=-1
        for i in s:
            a=int(i)
            sum+=a
            if maxx<a:
                maxx=a
        ans.append(sum)
        ans.append(maxx)
        return ans

def func6(m,n):
    ans=None
    if m<100:
        ans=m
    else:
        length=len(str(m))
        highnum=m//(10**(length-1))
        if highnum+n>=10:
            t=(highnum+n)%10
            ans=t*(10**(length-1))+m%((10**(length-1)))
        else:
            t=highnum+n
            ans = t * (10 ** (length - 1)) + m % ((10 ** (length - 1)))
    return ans
        
def func7(k, lst):
    if k>=len(lst):
        ans=lst[::-1]
    else:
        ans=lst[k-1::-1]+lst[k::]
    return ans

def func8(v, lst):
    ans=[]
    for i in lst:
        sum=0
        for j in str(i):
            sum+=int(j)
        if sum/len(str(i))>=v:
            ans.append(i)
    return ans

if __name__=="__main__":
    print(func1(-4))
    print(func1(1))
    print('-'*300)
    print(func2(11))
    print(func2(9))
    print(func2(5))
    print(func2(2))
    print(func2(-1))
    print('-' * 300)
    print(func3(3,12))
    print('-' * 300)
    print(func4(2,22))
    print('-' * 300)
    print(func5(-123456))
    print('-' * 300)
    print(func6(345,8))
    print('-' * 300)
    print(func7(4,[3,4,1,5,2]))
    print('-' * 300)
    print(func8(2.5,[123,1234]))





