#!/usr/bin/env python
# coding=utf-8

import re

str =  '<a rel="noreferrer" href="/p/6672389534" title="【冰玉麒麟】怎么办啊，我好喜欢郭麒麟啊，我是前天 才第一次接" target="_blank" class="j_th_tit ">【冰玉麒麟】怎么办啊，我好喜欢郭麒麟啊，我是前天 才第一次接</a>'



#pattern = re.compile(r'<a rel="noreferrer" herf="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')

pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')

url_title = pattern.findall(str)
print(url_title)

for url, title in url_title:
    print("url = ", url)
    print("url_title = ", url_title)

