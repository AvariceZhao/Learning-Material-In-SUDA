#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式中常用函数的使用

import re
test_str = "This is a program named 'hello world'. It outputs two words. They are 'hello' and 'world'."
line_len = 60

m1 = re.compile(r"hello")
m2 = re.compile(r"this")
m3 = re.compile(r"this", re.I)

print(m1.match(test_str))
print(m2.match(test_str))
print(m3.match(test_str))
print("-"*line_len, 1)

print(m1.search(test_str))
print(m2.search(test_str))
print(m3.search(test_str))
print("-"*line_len, 2)

print(m1.findall(test_str))
print(m2.findall(test_str))
print(m3.findall(test_str))
print("-"*line_len, 3)

s1 = m1.finditer(test_str)
print(s1, len(list(s1)))
s2 = m2.finditer(test_str)
print(s2, len(list(s2)))
s3 = m3.finditer(test_str)
print(s3, len(list(s3)))
