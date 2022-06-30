import os


def operation(op: str, lst1: list, lst2: list):
    '''
    根据操作符op返回对应的布尔操作的结果
    :param op:布尔操作的类型
    :param lst1:第一个列表
    :param lst2:第二个列表
    :return:返回操作后的列表
    '''

    if op == "OR":
        return union(lst1, lst2)  # 取并集
    else:
        return inter(lst1, lst2)  # 取交集


def union(lst1: list, lst2: list):  # 求并集
    i = 0
    j = 0
    c = []
    while i < len(lst1) or j < len(lst2):  # 利用双指针以O(n)的时间复杂度求并集
        if i < len(lst1) and (j >= len(lst2) or lst1[i] < lst2[j]):
            c.append(lst1[i])
            i += 1
        elif j < len(lst2) and (i >= len(lst1) or lst1[i] > lst2[j]):
            c.append(lst2[j])
            j += 1
        elif i < len(lst1) and j < len(lst2) and lst1[i] == lst2[j]:
            c.append(lst1[i])
            i += 1
            j += 1
    return c


def inter(lst1: list, lst2: list):  # 求交集
    i = 0
    j = 0
    c = []
    while i < len(lst1) and j < len(lst2):  # 利用双指针以O(n)的时间复杂度求交集
        if lst1[i] == lst2[j]:
            if not c or lst1[i] != c[-1]:
                c.append(lst1[i])
            i += 1
            j += 1
        elif lst1[i] < lst2[j]:
            i += 1
        elif lst1[i] > lst2[j]:
            j += 1
    return c


def WordToIdList(word: str):
    '''
    输入单词返回单词所在文件名的编号列表
    :param word: 查找的单词
    :return: 包含单词所在文件名的编号列表
    '''

    if word not in indexDict.keys():  # 防止出现KeyError
        return []

    temp = indexDict[word]  # 包含单词的文件名列表
    lst = []
    for i in range(len(temp)):
        lst.append(NameToNum[temp[i]])  # 将文件名转为编号
    return lst


def Query(s: str):
    # 分离出单词和布尔操作,如果不满三个部分则判断为单词查询
    temp = s.split()  # 获得由单词和操作符构成的列表

    words = []  # 存储所有查询词

    if len(temp) == 1:  # 单个词语查询
        word1 = s
        word2 = s
        op = 'OR'

        ans = operation(op, WordToIdList(word1), WordToIdList(word2))  # 进行布尔运算
        words.append(word1)  # 存储查询词

    else:  # 多词查询 temp=[word1,op1,word2,op2,word3,op3,word 4...]

        if len(temp) % 2 == 0:  # 语句有误
            print("查询语句有误，请按照 word1 op1 word2 op2 word3 op3 word4...的格式输入查询语句")
            return

        if len(temp) == 3:  # 长度为3则只有一次布尔操作
            word1 = temp[0]
            op = temp[1]
            word2 = temp[2]

            words.append(word1)
            words.append(word2)
            # 对特殊情况进行判断,避免出现因为字典中缺少key引报错

            ans = operation(op, WordToIdList(word1), WordToIdList(word2))
        else:

            # 先进行第一次操作获得一个列表
            word1 = temp[0]
            op = temp[1]
            word2 = temp[2]

            words.append(word1)
            words.append(word2)
            ans = operation(op, WordToIdList(word1), WordToIdList(word2))  # 对第一个列表进行布尔操作

            # 用第一的列表不断和后面的操作
            OpIndex = 3  # 取出操作符
            WordIndex = 4  # 取出单词

            while WordIndex < len(temp):
                op = temp[OpIndex]  # 取出操作符
                word0 = temp[WordIndex]  # 取出单词

                words.append(word0)
                ans = operation(op, ans, WordToIdList(word0))  # 用当前列表和新的单词获得的列表进行操作
                OpIndex += 2  # 获取下一个操作符
                WordIndex += 2  # 获取下一个单词

    for i in range(len(ans)):  # 将编号转为文件名便于打开文件
        ans[i] = NumToName[ans[i]]

    ans.sort() # 将文件名排序

    # 获取文件名列表
    outFile = open("./TestExample/" + s + ".txt", "w+", encoding='utf8')  # 打开输出文件
    outFile.write("符合查询结果的文件为:" + str(ans) + '\n'*2)  # 输出所有符合结果的文件名
    print("符合查询结果的文件为:\n", ans)
    for name in ans:
        print(str(name)+'\n')
        outFile.write(str(name)+'\n')  # 输出当前文件名

        f = open(root + str(name), encoding='utf8')  # 打开文件
        # if BOOL == 'OR':

        for line in f.readlines():  # 按行读取
            # if word1 in line or word2 in line:
            flag = False
            for Word in words:  # 判断当前行是否包含任意查询词
                if Word in line:
                    flag = True
                    break
            if flag:  # 如果包含
                s = line.strip()  # 取出行末多余换行符
                for Word in words:  # 对词语进行标注
                    s = s.replace(Word, "#" + Word + "#")
                print(s, end='\n')
                outFile.write(s + '\n')  # 输出标注后的语句

        f.close()  # 关闭该文件
        outFile.write('\n')
        print('\n',end="")
    outFile.close()  # 遍历完列表中所有文件后关闭输出文件



file = open("./index/index.txt", encoding='utf8')
lst = file.readlines()
file.close()

print("开始初始化")
# 利用已生成的倒排索引生成字典便于查询
indexDict = dict()
for a in lst:
    st = -1
    for j in a:
        if j == '[':
            break
        st += 1
    name = a[:st:]
    indexDict[name] = eval(a[len(name) + 1::])

# 给文件名编号并存到字典里
root = "./data-1k/"
cnt = 1
NameToNum = dict()
NumToName = dict()
for i in sorted(list(os.walk(root))[0][2]):  # 排序
    NameToNum[i] = cnt
    NumToName[cnt] = i
    cnt += 1
print("初始化完成")

# 查询操作
q = input("请输入查询内容,支持单个词语查询和AND OR布尔查询,布尔查询格式为 单词1 AND/OR 单词2 AND/OR 单词3 AND/OR 单词4...... ,输入###退出")
while q != '###':
    Query(q.strip())
    q = input("请输入查询内容,支持AND OR查询,输入###退出").strip()
print("程序退出")
