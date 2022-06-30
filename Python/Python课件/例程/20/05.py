#!/usr/bin/python
# -*- coding: utf-8 -*-
#遍历文件夹

import os
import os.path

rootdir=r"D:\Program Files\Foxmail 7.2"
lst = list(os.walk(rootdir))
for item in lst:
    print(item)
