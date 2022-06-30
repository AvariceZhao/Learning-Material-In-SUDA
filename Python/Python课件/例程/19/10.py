#!/usr/bin/python
# -*- coding: utf-8 -*-
#正则表达式的 split 的模糊情况

import re

example = r"one|two|three|four|five|six"

pattern = re.compile(r"[|]")
print(pattern.split(example))

pattern = re.compile(r"[\|]")
print(pattern.split(example))

example = r"one[two[three]four[five]six"

pattern = re.compile(r"[\[\]]")
print(pattern.split(example))
