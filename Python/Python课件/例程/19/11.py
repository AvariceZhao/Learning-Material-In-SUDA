#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式的特殊匹配字符

import re

m = re.search(r"[?+{}()|]+","字符串中包含?{?})+(+?|等符号")
if m != None:
    print(m.group())
else:
    print("Not found.")

m = re.search(r"[\?\+\{\}\(\)\|]+","字符串中包含?{?})+(+?|等符号")
if m != None:
    print(m.group())
else:
    print("Not found.")
