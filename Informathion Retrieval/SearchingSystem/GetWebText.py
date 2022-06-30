import os
from bs4 import BeautifulSoup


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
            file = open("./data/" + i, 'w+', encoding='utf8')
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
GetWebText()
