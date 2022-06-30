#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式的 split

import re

example = "On these pages you will find Springer’s journals, ebooks and proceedings \
in all areas of Computer Science, serving researchers, professionals, lecturers and \
students. We publish many prestigious journals in Computer Science, including a number \
of fully open access journals."

pattern = re.compile(r"[,.: ]")
lst1 = pattern.split(example)
lst2 = list(filter(lambda x: True if len(x)!=0 else False, lst1))
print(lst2, len(lst2))
