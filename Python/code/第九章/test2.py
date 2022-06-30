import os
import datetime
def list_all_files1(rootdir):
    files,dirs=[],[rootdir]
    for item in dirs:
        for p in os.listdir(item):
           # print(os.listdir(item))
            path=os.path.join(item,p)
           # print(path)
            if os.path.isfile(path):
                files.append(path)
            elif os.path.isdir(path):
                dirs.append(path)
    return files
def list_all_files2(rootdir):
    files=[]
    list=os.listdir(rootdir)
    for i in range(0,len(list)):
        path=os.path.join(rootdir,list[i])
        if os.path.isdir(path):
            files.extend(list_all_files2(path))
        if os.path.isfile(path):
            files.append(path)
    return files
root=r"C:\Users\SUzp\Desktop\CS\PYTHON\python\code"
#fs=list_all_files1(root)
fs=list_all_files2(root)
for item in fs:
   print(item)
print("|fs1|=%d"%len(fs))