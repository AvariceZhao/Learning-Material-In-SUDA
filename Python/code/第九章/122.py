import os
if not os.path.isfile('largefile.txt'):
    print(f'"largefile.txt"不存在')
    exit()
f=open('largefile.txt','r')

l=[0]
while ch:=f.read(1):
    if ch=='\n':
        l.append(f.tell())
print("总行数=",len(l)-1)

while 1:
    try:
        n=int(input("输入要输出的行数"))
    except ValueError:
        print('输入的行号必须为一个整数')
        continue
    if n<0 or n>=len(l):
        print('行数错误')
        continue
    elif n==0:
        print('程序退出')
        break
    f.seek(l[n-1])
    print(f.readline())
