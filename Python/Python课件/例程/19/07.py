#!/usr/bin/python
# -*- coding: utf-8 -*-
#求字符串中的整数和
import re

number_str = "73, #?!=,  123,456,   hello  789, -12, 101"

m1 = re.findall(r"-?\d+", number_str)

if m1 == None:
    print("ERROR")
else:
    #print(m1)
    m2 = list(map(int, m1))
    print(sum(m2))
