import os
root=os.getcwd()+'\Folder'
all=list(os.walk(root))[0][2]
root1=root+'\merge.txt'
root+=r'\text'
with open(root1,'a+') as file:
    for i in all:
        with open(root+i[4]+'.txt') as f:
            txt=f.read()
            file.write(txt)