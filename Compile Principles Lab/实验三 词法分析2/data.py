f=open('number.txt','r')
f1=open('number1.txt','w')
lines=int(f.readline())
print(lines)
for i in range(lines):

    data=f.readline(). split()
    print(data)
    for j in data:
        if len(j)>=2:
            d='r'+str(int(j[1:])+206)
            f1.write(d+' ')
        else:
            f1.write(j)
    f1.write('\n')
f.close()
f1.close()