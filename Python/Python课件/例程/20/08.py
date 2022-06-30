#!/usr/bin/python
# -*- coding: utf-8 -*-
#遍历文件夹对比

import os

#非递归方法
def list_all_files1(rootdir):
    _files, _dirs = [], [rootdir]
    for item in _dirs:
        for p in os.listdir(item): #列出文件夹下所有的目录与文件
            path = os.path.join(item, p)
            if os.path.isfile(path) and path.endswith(".py"):
                _files.append(path)
            elif os.path.isdir(path):
                _dirs.append(path)
    return _files

#递归方法
def list_all_files2(rootdir):
    _files = []
    list = os.listdir(rootdir) #列出文件夹下所有的目录与文件
    for i in range(0,len(list)):
        path = os.path.join(rootdir,list[i])
        if os.path.isdir(path):
            _files.extend(list_all_files2(path))
        if os.path.isfile(path) and path.endswith(".py"):
            _files.append(path)
    return _files


root = r"E:\Sync\Teaching\Python\02"
_fs1 = list_all_files1(root)
_fs2 = list_all_files2(root)
print("|_fs1| = %d" % len(_fs1), ", |_fs2| = %d" % len(_fs2))

_fs1 = set(list_all_files1(root))
_fs2 = set(list_all_files2(root))
print("|_fs1| = %d" % len(_fs1), ", |_fs2| = %d" % len(_fs2))

print(_fs1 == _fs2)