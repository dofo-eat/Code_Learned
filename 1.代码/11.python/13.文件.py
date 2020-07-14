#!/usr/bin/env python
# coding=utf-8

#写文件
file = open("./input", "w", encoding = 'utf-8')
file.write("hello world")
file.write("\n")


#按行写
file.writelines(['write', 'line'])
file.close()
