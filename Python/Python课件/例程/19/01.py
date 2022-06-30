#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式的两种基本用法

import re
test_str = "This is a program named 'hello world'. It outputs two words. They are 'hello' and 'world'."

#方法1：直接使用re模块的函数
m = re.findall(r"hello", test_str)
if m != None:
    print(m)
else:
    print("Not found.")

#方法2：使用compie函数
m = re.compile(r"hello")
s = m.findall(test_str)
if s != None:
    print(s)
else:
    print("Not found.")

#改变模式
m = re.compile(r"'hello'")
s = m.findall(test_str)
if s != None:
    print(s)
else:
    print("Not found.")

