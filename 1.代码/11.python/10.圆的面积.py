#!/usr/bin/env python
# coding=utf-8

import math

'''def circle(r):
    result = math.pi * r * r
    return result
r = float(input("输入半径："))
print("半径为", r ,"面积是：" ,circle(r))
'''
r = float(input("半径："))
result = lambda r : math.pi * r * r
print("半径为", r ,"面积是：" ,result(r))

