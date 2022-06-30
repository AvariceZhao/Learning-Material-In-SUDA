import re
import os


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


def maxmatch(fileName, sentences):  # 最大分词匹配
    for s in sentences:
        i = 0
        while i < len(s):
            if s[i] in ['\n', '\r', ' ', '', '\xa0', '\t', '|']:  # 过滤特殊字符
                i += 1
                continue
            for l in range(maxlen, 0, -1):  # 从大到到小枚举所有可能长度
                if (l == 1) or (i + l < len(s) and s[i: i + l] in WordDict[l]):  # 如果长度为1或者在词典中则分词
                    words = s[i: i + l]
                    if words in StopWords:
                        i += l
                        break
                    if words in index.keys():  # 添加索引
                        if fileName not in index[words]:
                            index[words].append(fileName)
                    else:
                        index[words] = [fileName]
                    i += l
                    break


WordDict = [set() for i in range(20)]  # 创建停词典列表，用ilst套set存储，查找时更加高效
f = open("./dict/dict.txt.big.txt", "r", encoding="utf-8-sig")
l = f.readlines()
f.close()
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

count = 1
for f in os.listdir("./data-1k/"):  # 对已处理的文件进行计数
    maxmatch(f, devided(f))
    if count % 50== 0:
        print('-',end='')
    count += 1
print('100%')


file = open('out.txt', 'w+', encoding='utf8')
for i in index.keys():  # 输出文件
    file.write(i + " "+str(index[i]) + '\n')
file.close()


print("Completed!")
