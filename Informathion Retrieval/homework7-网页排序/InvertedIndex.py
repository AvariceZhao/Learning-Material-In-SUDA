import re
import os
import math

def devided(file):
    f = open("data-1k/" + file, "r", encoding="utf-8-sig")
    t = ""
    s = f.readline()  # 按行读入，方便去除句子link
    while s:
        if s in ["title:\n", "body:\n", "\n"]:
            s = f.readline()
            continue
        if s == "link:\n":
            break
        t += s
        s = f.readline()
    f.close()

    return re.split("[,.?:：、\n\xa0;'，。？！!；]", t)

def getIdft(dft): #计算Idgt
    return math.log(N/dft,10)

def getWtd(Tftd): #计算Wtd
    if Tftd>0:
        return 1+math.log(Tftd,10)
    else:
        return 0


def maxmatch(fileName, sentences):  # 最大分词匹配
    worddict=dict()
    for s in sentences:
        i = 0
        while i < len(s):
            if s[i] in ['\n', '\r', ' ', '', '\xa0', '\t', '|']:  # 过滤特殊字符
                i += 1
                continue
            for l in range(maxlen, 0, -1):  # 从大到到小枚举所有可能长度
                if (l == 1) or (i + l <=len(s) and s[i: i + l] in WordDict[l]):  # 如果长度为1或者在词典中则分词
                    words = s[i: i + l]


                    if words in StopWords:
                        i += l
                        break
                    if words not in index.keys():#初始化列表
                        index[words] = []
                    if words in worddict.keys():
                        worddict[words]+=1 #计数


                    else:
                       worddict[words]=1 #计数

                    i += l
                    break

    mod = 0

    for word0 in worddict.keys():

       index[word0].append([fileName,getWtd(worddict[word0])]) #存储wtd
       mod+=getWtd(worddict[word0])**2 #计算|di|
    mod=math.sqrt(mod)
    DocMod[fileName]=mod#存储|di|




WordDict = [set() for i in range(20)]  # 创建停词典列表，用ilst套set存储，查找时更加高效
f = open("./dict/dict.txt.big.txt", "r", encoding="utf-8-sig")
l = f.readlines()
f.close()
DocMod=dict()
maxlen = 0
for i in range(len(l)):
    WordDict[len(l[i].split()[0])].add(l[i].split()[0])  # 将词语添加到对应列表中
    maxlen = max(maxlen, len(l[i].split()[0]))  # 计算词语最大长度，在分词时进行枚举

StopWords = set()
for f in os.listdir("stopwords"):  # 创建两个停用词列表
    file = open("./stopwords/" + f, "r", encoding="utf-8-sig")
    for i in file.readlines():
        StopWords.add(i.strip())  # 去除尾部换行符

index = dict()  # 创建最终索引字典
N=len(os.listdir("./data-1k/"))
count = 1

for f in os.listdir("./data-1k/"):  # 对已处理的文件进行计数
    maxmatch(f, devided(f))

    if count % 50== 0:
        print('-',end='')
    count += 1
print('100%')




for word in index:
    index[word]=[getIdft(len(index[word]))]+index[word]

file = open('Testout.txt', 'w+', encoding='utf8')#输出文件
file.write(str(DocMod)+'\n')
for i in index.keys():  # 输出文件
    file.write(i + " "+str(index[i]) + '\n')
file.close()


print("Completed!")
