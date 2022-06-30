import re
f=open('sample.txt','r')
lst=[]
words=[]
d=dict()
get=re.compile(r'[a-z]+')#通过正则表达式提取所有单词
for i in f.readlines():
    for j in get.findall(i.lower()):#利用正则表达式提取单词并转小写存储到word列表中
        words.append(j.lower())
for i in words:#统计单词出现频率
    if i not in d.keys():
        d[i]=1
    else:
        d[i]+=1
f.close()
print("Completed!")
f=open('dict.index','w+')
for i in d:#输出文件
    f.write(i+'\t'+str(d[i])+'\n')
f.close()
a=input("请输入要查询的单词,输入###退出")
while not a=="###":
    if a not in d.keys():
        print("0")
    else:
        print(d[a])
    a = input("请输入要查询的单词,输入###退出")
