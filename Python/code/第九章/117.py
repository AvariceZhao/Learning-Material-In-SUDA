with open('filenames.txt') as f:
    a=f.readlines()
l=len(a)
l1=[]
for i in a:
    l1.append(i.replace('\n',''))
count=1
for i in range(len(l1)):
        with open(l1[i],'w+') as f:
            pass
for i in range(len(l1)):
        with open(l1[i],'w+') as f:
            if i==0:
                f.write(l1[len(l1)-1])
            else:
                f.write(l1[i-1])


