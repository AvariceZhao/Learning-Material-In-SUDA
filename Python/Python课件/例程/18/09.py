#!/usr/bin/python
# -*- coding: utf-8 -*-
#eval的使用

while True:
    num1 = input("第1个数=")
    op   = input("运算符 =")
    num2 = input("第2个数=")
    command = num1 + op + num2
    if command == "":
        break
    print(command)
    print(eval(command))
