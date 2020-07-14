#!/usr/bin/env python
# coding=utf-8

#输出文件名
fo = open("./input", "r+")
print("文件名：", fo.name)

#文件指针的位置
str = '\nwww.haizeix.com'
fo.seek(0, 2) #表示当前./input结尾的位置
line = fo.write(str)#写入的字符串的长度

#读取文件所有内容
fo.seek(0)
for index in range(3):
    line = next(fo)
    print("文件行号 %d - %s" %(index, line))
fo.close()
