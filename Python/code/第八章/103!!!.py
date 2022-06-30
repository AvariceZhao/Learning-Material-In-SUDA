def change(a,b,d):
    if a<2 or a>16 or b<2 or b>16:
        return None
    else:
        fx={'1':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'A':10,'B':11,'C':12,'D':13,'E':14,'F':15}
        gx={0:0,1:1,2:2,3:3,4:4,5:5,6:6,7:7,8:8,9:9,10:'A',11:'B',12:'C',13:'D',14:'E',15:'F'}
        #fx用于将原进制转化为十进制
        #gx用于将转化完的十进制转化到目标进制
        l=len(d)
        t=0#t代表原数据转化为十进制后的数据
        if a<10:
            for i in range(l):
                t+=(a**i)*int(d[l-i-1])
        elif a==10:
            t=int(d)
        else:
            for i in range(l):
               t+=((a**i)*int(fx[d[l-i-1]]))
            #    print(a**i,fx[d[l-i-1]])
            # print(t,end='=t\n')
        l1=[]
        while t>=1:
            l1.append(gx[t%b])
            # print(gx[t%b],end=" ")
            t=t//b
            # print(t)

        return l1
a=int(input("input thee nums,divided by SPACE"))
b=int(input("input thee nums,divided by SPACE"))
d=input("input thee nums,divided by SPACE")
ans=change(a,b,d)
ans.reverse()
for i in ans:
    print(i,end="")