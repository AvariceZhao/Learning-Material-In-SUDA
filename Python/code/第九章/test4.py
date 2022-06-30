import os
root=r'C:\Users\SUzp\Desktop\CS\PYTHON\python\code\第九章\file1'
prefix='test'
suffix='.txt'
start=1
fl=os.listdir(root)
bit=len(str(len(fl)))
for file in fl:
    if not os.path.isfile(root+file):
        continue
    new_name=prefix+('0'*bit+str(start))[-bit:]+suffix
    print(root+new_name)
    os.rename(root+file,root+new_name)
    start+=1