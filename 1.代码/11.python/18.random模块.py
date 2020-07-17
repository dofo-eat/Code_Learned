#!/usr/bin/env python
# coding=utf-8

import random

#0-1之间的随机数

print(random.random())

#指定范围的随机数
print(random.randint(10, 100))

#随机获取列表的一个值
list1 = [1, 2 , 3, 4]
print(random.choice(list1))
