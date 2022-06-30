import os
from bs4 import BeautifulSoup
import re
import math
def GetWebText():
    def judge(s: str):
        for j in s:
            if not (j == '\n' or j == ' ' or j == '\t' or j == '\v' or j == '\f' or j == '\r'):
                return False
        return True
    print('开始提取WebCode文件夹下的网页正文')
    root = './WebCode/'
    lst = list(os.walk(root))
    names = lst[0][2]

    for i in names:
        soup = BeautifulSoup(open("./WebCode/" + i, 'r', encoding='utf8'), 'lxml')
        if 'txt' in i:
            file = open("./data-1k/" + i, 'w+', encoding='utf8')
            file.write('title:\n')
            file.write(soup.title.text)
            file.write('\n')
            # process body
            file.write('\nbody:\n')
            f = open('temp.txt', 'w+', encoding='utf8')
            lst = soup.body.text
            f.write(lst)
            f.close()
            f = open('temp.txt', 'r', encoding='utf8')
            a = f.readlines()
            f.close()

            while a[0] == '\n':
                a.pop(0)
            a.reverse()
            a.reverse()
            for j in range(len(a) - 1):
                if judge(a[j]):
                    if not judge(a[j + 1]):
                        file.write('\n')
                else:
                    file.write(a[j])

            file.close()
    print('网页正文提取完成')
    os.remove('temp.txt')

def GetInvertedIndex():
    def devided(file):
        f = open("./WebText1/" + file, "r", encoding="utf-8-sig")
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

 #       return re.split("[,.?:：、\n\xa0;'，。？！!；]", t)

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

        # print(" ".join(Words))
        for word in Words:

            if word not in index.keys():
                index[word] = []
            if word in worddict.keys():
                worddict[word] += 1
            else:
                worddict[word] = 1
        # for s in sentences:
        #     i = 0
        #     while i < len(s):
        #         if s[i] in ['\n', '\r', ' ', '', '\xa0', '\t', '|']:  # 过滤特殊字符
        #             i += 1
        #             continue
        #         for l in range(maxlen, 0, -1):  # 从大到到小枚举所有可能长度
        #             if (l == 1) or (i + l <=len(s) and s[i: i + l] in WordDict[l]):  # 如果长度为1或者在词典中则分词
        #                 words = s[i: i + l]
        #
        #
        #                 if words in StopWords:
        #                     i += l
        #                     break
        #                 if words not in index.keys():
        #                     index[words] = []
        #                 if words in worddict.keys():
        #                     worddict[words]+=1
        #
        #
        #                 else:
        #                    worddict[words]=1
        #
        #                 i += l
        #                 break

        mod = 0

        for word0 in worddict.keys():
            index[word0].append([fileName, getWtd(worddict[word0])])
            mod += getWtd(worddict[word0]) ** 2
        mod = math.sqrt(mod)
        DocMod[fileName] = mod

    print('开始创建倒排索引')
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
    N = len(os.listdir("./data/"))

    for f in os.listdir("./data/"):  # 对已处理的文件进行计数
        maxmatch(f, devided(f))

    for word in index:
        index[word] = [getIdft(len(index[word]))] + index[word]

    file = open('./InvertedIndex./InvertedIndex1.txt', 'w+', encoding='utf8')
    file.write(str(DocMod) + '\n')
    for i in index.keys():  # 输出文件
        file.write(i + " " + str(index[i]) + '\n')
    file.close()

    print("倒排索引创建完成")

def WebRankQuery():
    def WordMatch(s: str):  # 传入一句话，进行分词
        sentences = [s]
        ans = []
        for i in sentences:
            back = 0
            counts = 0
            l = len(i)
            while counts < l:
                for j in range(maxlen, 0, -1):  # 枚举切片长度
                    if i[back:back + j] in words:  # 判断是否匹配，匹配则打印
                        ans.append(i[back:back + j])
                        back += j  # 将当前位置指针右移
                        counts += j
                        break
                    if j == 1:
                        ans.append(i[back])
                        back += 1
                        counts += 1
                        break
        return ans

    def GetCos(FileName: str, WordList: list):  # 计算每个文档的cos
        '''

        :param FileName:文档名
        :param WordList: 词袋
        :return:
        '''

        Wtd = []  # 存储wtd
        Idft = []  # 存储idft

        for word in WordList:  # 遍历所有词 ,存储wtd,idft
            if word in indexDict.keys():
                Idft.append(indexDict[word][0])
            else:
                Idft.append(0)
            if word in WordTOFileName.keys():
                if FileName not in WordTOFileName[word]:
                    Wtd.append(0)
                else:
                    Wtd.append(indexDict[word][WordTOIndex[word][FileName]][1])
            else:
                Wtd.append(0)

        up = 0
        down = 0
        for i in range(len(Wtd)):  # 计算cos的分子分母
            up += Wtd[i] * Idft[i]  # 计算分子
            down += Idft[i] * Idft[i]  # 计算分母的一部分
        down = math.sqrt(down)
        down = down * DocMod[FileName]  # 获得最终分母
        if down == 0:  # 特判分母是否为0
            return 0
        else:
            return up / down  # 返回分母

    def OutAns(ans: list, WordList: list, Q: str):  # 输出查询结果到文件
        QueryAnswer=list()
        outFile = open("./QueryExample/" + Q + ".txt", "w+", encoding='utf8')
        if len(ans) == 0:
            print('无法查询到相关文档')

            outFile.write('无法查询到相关文档')
            outFile.close()
            return
        root = "./data/"
        for unit in ans:

            print(unit[0] + " (余弦相似度:{})".format(unit[1]), end='\n')
            outFile.write(unit[0] + " (余弦相似度:{})".format(unit[1]) + '\n')
            Content=""
            f = open(root + str(unit[0]), encoding='utf8')  # 打开文件
            for line in f.readlines():
                flag = False
                for Word in WordList:  # 判断当前行是否包含任意查询词
                    if Word in line:
                        flag = True
                        break
                if flag:  # 如果包含
                    s = line.strip()  # 取出行末多余换行符
                    for Word in WordList:  # 对词语进行标注
                        s = s.replace(Word, "#" + Word + "#")
                    print(s, end='\n')
                    Content+=s
                    outFile.write(s + '\n')  # 输出标注后的语句

            outFile.write('\n')
            print('\n', end="")
            outFile.write('\n')
            QueryAnswer.append([unit[0][0:-4],Content])
            f.close()
        outFile.close()
        print(QueryAnswer)


    def Query(s: str):  # 查询函数
        l = len(s.split())

        if l == 1:  # 判断给定语句是否已经用空格分词
            WordList = WordMatch(s)
        else:
            WordList = s.split()

        FileList = set()  # 存储待排序文件

        for i in WordList:
            if i in indexDict.keys():
                for j in range(1, len(indexDict[i])):
                    FileList.add(indexDict[i][j][0])
        FileList = list(FileList)

        ans = []
        for File in FileList:
            ans.append([File, GetCos(File, WordList)])
        ans.sort(key=lambda x: x[1], reverse=True)  # 按照cos值排序

        OutAns(ans, WordList, s)  # 输出查询结果

    print('开始初始化...')
    print('开始加载分词词典...')
    words = []

    f = open("./Dict/dict.txt.big.txt", "r", encoding="utf-8-sig")
    for i in f.readlines():
        words.append(i.split()[0])
    words.pop(0)
    words = list(set(words))
    maxlen = 0
    for i in words:
        maxlen = max(maxlen, len(i))

    print('分词词典加载完成!')
    print('开始加载倒排索引文件...')

    file = open("./InvertedIndex/InvertedIndex1.txt", encoding='utf8')

    MOD = file.readline()
    lst = file.readlines()
    file.close()

    # 利用已生成的倒排索引生成字典便于查询  索引格式：词语 [idft,[fileNmame,wtd],[fileName,wtd]]
    indexDict = dict()
    DocMod = eval(MOD)
    WordTOFileName = dict()  # 一个词存在的所有文件名
    WordTOIndex = dict()  # 给定词找到索引获取wtd
    for a in lst:
        st = -1
        for j in a:
            if j == '[':
                break
            st += 1
        name = a[:st:]
        try:
            indexDict[name] = eval(a[len(name) + 1::])
        except BaseException:
           pass

    for i in indexDict.keys():
        WordTOFileName[i] = []
        WordTOIndex[i] = dict()
        for j in range(1, len(indexDict[i])):
            WordTOFileName[i].append(indexDict[i][j][0])
            WordTOIndex[i][indexDict[i][j][0]] = j

    # indexDict[word][WordTOIndex[word]][1]

    print('索引文件加载完成!')

    s = input('请输入查询语句，输入###退出')
    while s != '###':
        Query(s)

        s = input('请输入查询语句，输入###退出')
# GetWebText()
# GetInvertedIndex()
WebRankQuery()