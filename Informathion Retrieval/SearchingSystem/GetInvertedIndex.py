import re
import os
import math


def devided(file):
    f = open("./WebText/" + file, "r", encoding="utf-8-sig")
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
    return t




def getIdft(dft):
    return math.log(N / dft, 10)


def getWtd(Tftd):
    if Tftd > 0:
        return 1 + math.log(Tftd, 10)
    else:
        return 0


def maxmatch(fileName, sentences):  # 最大分词匹配
    worddict = dict()
    Words = sentences.split()


    for word in Words:
        if word not in StopWords:
            if word not in index.keys():
                index[word] = []
            if word in worddict.keys():
                worddict[word] += 1
            else:
                worddict[word] = 1

    mod = 0

    for word0 in worddict.keys():
        index[word0].append([fileName, getWtd(worddict[word0])])
        mod += getWtd(worddict[word0]) ** 2
    mod = math.sqrt(mod)
    DocMod[fileName] = mod


WordDict = [set() for i in range(20)]  # 创建停词典列表，用ilst套set存储，查找时更加高效
f = open("./dict/dict.txt.big.txt", "r", encoding="utf-8-sig")
l = f.readlines()
f.close()
DocMod = dict()
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
N = len(os.listdir("./WebText/"))
count = 1

for f in os.listdir("./WebText/"):  # 对已处理的文件进行计数
    maxmatch(f, devided(f))

    if count % 50 == 0:
        print('-', end='')
    count += 1
print('100%')

for word in index:
    index[word] = [getIdft(len(index[word]))] + index[word]

file = open('./InvertedIndex./InvertedIndex.txt', 'w+', encoding='utf8')
file.write(str(DocMod) + '\n')
for i in index.keys():  # 输出文件
    file.write(i + " " + str(index[i]) + '\n')
file.close()

print("Completed!")
