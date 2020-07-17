#!/usr/bin/env python
# coding=utf-8

import urllib.request

#像指定的URL发送一个请求， 获取一个回应
response = urllib.request.urlopen("http://www.haizeix.com")
#获取响应
content = response.read().decode('utf-8')
fo = open('./haizei.heml', 'w', encoding = 'utf-8')
print(content,file = fo)
fo.close()

#响应头信息
print(response.headers)
#响应码
print(response.status)
