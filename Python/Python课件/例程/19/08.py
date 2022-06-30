#!/usr/bin/python
# -*- coding: utf-8 -*-
#用正则表达式做替换

import re

example = r"In this page you will find 35 words and 20 errors."

#替换固定串
repl = "***"
new_str = re.sub(r"\d+", repl, example)
print(new_str)
print(re.subn(r"\d+", repl, example))

#替换非固定串
def repl_content(m):
    s = m.group()
    x = int(s) + 1
    return str(x)

print("-"*60)

new_str = re.subn(r"\d+", repl_content, example)
print(new_str)
print(new_str[0])