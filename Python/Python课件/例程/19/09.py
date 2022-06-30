#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式的 split 的模糊情况

import re

example = r"one,two,three.four/five\six?seven[eight]nine|ten"
pattern = re.compile(r"[,./\\?[\]\|]")
lst = pattern.split(example)
print(lst)

pattern = re.compile(r"[,./\\?[\]|]")
lst = pattern.split(example)
print(lst)

pattern = re.compile(r"[,./\\?\[\]|]")
lst = pattern.split(example)
print(lst)

pattern = re.compile(r"[,./\\?|\[\]]")
lst = pattern.split(example)
print(lst)
