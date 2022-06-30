import shutil
f=open('new.txt','w+')
f.close()
shutil.copy('copy.txt','new.txt')