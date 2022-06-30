
import math

def WordMatch(s: str):# 传入一句话，进行分词
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


def GetCos(FileName: str, WordList: list): #计算每个文档的cos
    '''

    :param FileName:文档名
    :param WordList: 词袋
    :return:
    '''

    Wtd = []#存储wtd
    Idft = [] #存储idft

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
    for i in range(len(Wtd)):#计算cos的分子分母
        up += Wtd[i] * Idft[i] #计算分子
        down += Idft[i] * Idft[i] #计算分母的一部分
    down = math.sqrt(down)
    down = down * DocMod[FileName]#获得最终分母
    if down==0: #特判分母是否为0
        return 0
    else:
        return up / down#返回分母

def OutAns(ans:list,WordList:list,Q:str): #输出查询结果到文件


    outFile = open("./TestExamlpe/" + Q + ".txt", "w+", encoding='utf8')
    if len(ans)==0:
        print('无法查询到相关文档')
        outFile.write('无法查询到相关文档')
        outFile.close()
        return
    root = "./data-1k/"
    for unit in ans:
        print(unit[0]+" (余弦相似度:{})".format(unit[1]),end='\n')
        outFile.write(unit[0]+" (余弦相似度:{})".format(unit[1])+'\n')

        f = open(root + str(unit[0]), encoding='utf8')  # 打开文件
        for line in f.readlines():
            flag=False
            for Word in  WordList:  # 判断当前行是否包含任意查询词
                if Word in line:
                    flag = True
                    break
            if flag:  # 如果包含
                s = line.strip()  # 取出行末多余换行符
                for Word in WordList:  # 对词语进行标注
                    s = s.replace(Word, "#" + Word + "#")
                print(s, end='\n')
                outFile.write(s + '\n')  # 输出标注后的语句

        outFile.write('\n')
        print('\n', end="")
        outFile.write('\n')
        f.close()
    outFile.close()


def Query(s: str): #查询函数
    l=len(s.split())


    if l == 1:  #判断给定语句是否已经用空格分词
        WordList=WordMatch(s)
    else:
        WordList=s.split()

    FileList = set() #存储待排序文件

    for i in WordList:
        if i in indexDict.keys():
            for j in range(1, len(indexDict[i])):
                FileList.add(indexDict[i][j][0])
    FileList = list(FileList)


    ans = []
    for File in FileList:
        ans.append([File, GetCos(File, WordList)])
    ans.sort(key=lambda x: x[1], reverse=True)#按照cos值排序

    OutAns(ans,WordList,s) #输出查询结果


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


file = open("./Inverted Index/Inverted Index.txt", encoding='utf8')

MOD=file.readline()
lst = file.readlines()
file.close()

# 利用已生成的倒排索引生成字典便于查询  索引格式：词语 [idft,[fileNmame,wtd],[fileName,wtd]]
indexDict = dict()
DocMod=eval(MOD)
WordTOFileName = dict()  # 一个词存在的所有文件名
WordTOIndex = dict()  # 给定词找到索引获取wtd
for a in lst:
    st = -1
    for j in a:
        if j == '[':
            break
        st += 1
    name = a[:st:]
    indexDict[name] = eval(a[len(name) + 1::])

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
