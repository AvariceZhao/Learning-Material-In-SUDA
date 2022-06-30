import os

if not os.path.isfile('largefile.txt'):
    print(f'"largefile.txt"不存在')
    exit()

lines=[0]

with open('largefile.txt') as f:
    while ch:=f.read(1):
        if ch=='\n':
            lines.append(f.tell())
    print('总行数：',len(lines))
    order=1
    while 1:
        try:
            order=int(input('请阁下输入行号（0以退出）：'))
        except ValueError:
            print('行号必须为数字。')
            continue
        
        if order<0 or order>len(lines):
            print('行号超限！')
            continue
        elif order==0:
            print('退出程序。')
            break
        f.seek(lines[order-1])
        print(f.readline().strip())