import os
import shutil
import datetime
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
root=r'C:\Users\SUzp\Desktop\CS\PYTHON\python'
l=list_all_files2(root)
file=[]
succ={}
fail={}
f=open('log.txt','w+',encoding='utf8')
for i in l:
    if i[-3::]=='tmp':
        temp=list(i.split('\\'))
        for j in temp:
            if 'tmp' in j:#j是文件名
                now_time = datetime.datetime.now()
                try:
                    os.remove(i)
                    succ[j]=now_time
                except BaseException:
                    fail[j]=now_time
f.write('Success\n')
for i in succ:
    print(i)
    f.write(i+':'+str(succ[i])+'\n')
f.write('Failure\n')
for i in fail:
    print(i)
    f.write(i+':'+str(fail[i])+'\n')
f.close()