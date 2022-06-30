import requests
import bs4
import time
import random

Webcount = 0
error = 0


def dfs(url: str):
    global Webcount

    try:
        s = requests.get(url, timeout=30)
        Webcount += 1
    except BaseException:
        global error
        error += 1
        return

    s.encoding = 'utf8'
    AllWebs.append(url)
    soup = bs4.BeautifulSoup(s.text, 'lxml')
    l = soup.find_all('a')
    tempWeb = []

    try:
        f = open('./web4/' + soup.find_all('title')[0].text + str(Webcount) + '.txt', 'w+', encoding='utf8')
        f.write(url + s.text)
        f.close()
    except BaseException:
        return

    for link in l:  # 获得这个网页中所有包含suda的超链接

        t = link.get('href')
        if t:
            if 'scst.suda.edu.cn/' in t and ('htm' in t or 'html' in t) and 'http' in t:
                tempWeb.append(t)
            else:
                if "http" not in t and ('htm' in t or 'html' in t):  # 相对网页
                    tempWeb.append(root[:-1] + t)
    if len(tempWeb) == 0:
        return

    flag = False
    for newurl in tempWeb:
        if newurl not in AllWebs:
            flag = True
            break

    if not flag:  # 如果当前的网页包含的链接都被爬取过，就直接返回
        return
    else:
        for newurl in tempWeb:
            if newurl not in AllWebs:
                print(str(Webcount) + "访问-" + newurl)
                dfs(newurl)


AllWebs = ["http://scst.suda.edu.cn/"]

root = "http://scst.suda.edu.cn/"
dfs(root)
print(len(AllWebs))
