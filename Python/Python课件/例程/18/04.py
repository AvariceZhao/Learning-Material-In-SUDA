#!/usr/bin/python
# -*- coding: utf-8 -*-
#格式化字符串 - 字符串的 format 函数3

data = [{"x":1, "y":1, "z":1}, {"x":2.7431, "y":3.457, "z":4.119}]

for item in data:
    print("坐标位置：x={x}, y={y}, z={z}.".format(**item))
print("-"*60, 1)

for item in data:
    print("坐标位置：x={x:8}, y={y:8}, z={z:8}.".format(**item))
print("-"*60, 2)

for item in data:
    print("坐标位置：x={x:<8}, y={y:<8}, z={z:<8}.".format(**item))
print("-"*60, 3)

for item in data:
    print("坐标位置：x={x:#^8}, y={y:?^8}, z={z:^8}.".format(**item))
print("-"*60, 4)

for item in data:
    print("坐标位置：x={x:.2f}, y={y:.2f}, z={z:.2f}.".format(**item))
print("-"*60, 5)

for item in data:
    print("坐标位置：{{x={x:.2f}}}, y={y:.2f}, z={z:.2f}.".format(**item))
