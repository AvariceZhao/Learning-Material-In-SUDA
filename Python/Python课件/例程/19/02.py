#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式中普通字符串的匹配和搜索

import re
test_str = "This is a program named 'Hello World'. It outputs two words. They are 'hello' and 'world'."

#寻找一个单词的所有出现
m = re.findall(r"hello", test_str)
if m != None:
    print(1, m)
else:
    print("1 Not found.")

#寻找一个单词的所有完整出现
m = re.findall(r"\bis\b", test_str)
if m != None:
    print(2, m)
else:
    print("2 Not found.")

#寻找一个单词的所有出现（大小写不敏感）
m = re.findall(r"hello", test_str, re.I)
if m != None:
    print(3, m)
else:
    print("3 Not found.")

#寻找一个单词的所有出现及其位置
m = re.finditer(r"hello",  test_str, re.I)
if m != None:
    for item in m:
        print(4, item.group(), item.span())
else:
    print("4 Not found.")

#测试正则表达式的工作方式
m = re.finditer(r"aa",  "aaa")
if m != None:
    for item in m:
        print(5, item.group(), item.span())
else:
    print("5 Not found.")

