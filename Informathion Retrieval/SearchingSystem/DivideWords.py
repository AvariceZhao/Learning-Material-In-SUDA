import os
import jieba
import re
l=os.listdir('./data')
SentenceNum=0
Words=set()
WebNum=0
for i in l:
    InFile=open('./data/'+str(i),encoding='utf8')
    OutFile=open('./WebText/'+str(i),'w+',encoding='utf8')
    WebNum+=1
    temp=InFile.readlines()
    for sentence in temp:
        lst=re.split(r'[,.?!;，。？！； \n]',sentence)
        SentenceNum+=len(lst)
        s=" ".join(jieba.cut(sentence))
        for i in s.split():
            Words.add(i)
        OutFile.write(s)
    OutFile.close()
print('句子数:',SentenceNum)
print('词语数：',len(Words))
print('网页数：',WebNum)


