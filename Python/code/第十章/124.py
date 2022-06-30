import shutil
root=input("输入要复制的文件路径")
flag=True
str='utf8'
while flag:
    try:
        f=open(root,encoding=str)
        flag=False
    except FileNotFoundError:
        root=input("原文件不存在，重新输入要复制的文件路径")
    except IOError:
        root = input("原文件不可写，重新输入要复制的文件路径")
    except UnicodeError:
       str='ASCII'
shutil.copy(root,'newfile')