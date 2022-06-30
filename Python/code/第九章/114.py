with open('students_data.txt','r') as file:
    text=file.readlines()
a=[]
for i in text:
    a.append(list(i.split(' ')))
    print("{:<10} {:<15} {:>5}".format(*list(i.split(' '))))
a.sort(key=lambda x:int(x[2]))
n=int(input("请输入要删除小于的学号"))
with open('students_data.txt','r') as file:
    for i in a:
        if int(i[2])>n:
            for j in i:
                print(j,end=" ")
            print()

