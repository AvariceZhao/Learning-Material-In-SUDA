#!/usr/bin/python
# -*- coding: utf-8 -*-
#断言

n = 0

try:
    assert n != 0, "除数为0"
    print(10/n)
except AssertionError as e:
    print(e)
