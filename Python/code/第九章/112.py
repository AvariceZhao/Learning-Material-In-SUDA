with open("students_data.txt") as f:
    l=f.readlines()
f1=open('students_5.txt','a+')
for i in l:
    l=list(i.split(' '))
    if int(l[2])>3:
        f1.write(i)