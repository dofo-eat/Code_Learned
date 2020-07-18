#!/usr/bin/env python
# coding=utf-8

#import requests
from urllib.request import urlopen
from urllib import parse

def loadPage(url, filename):
    print("正在下载 ：" + filename)
    html = urlopen(url).read().decode("utf-8")
    print(html)
    return html

#将html内容写到本地
def writePage(html, filename):
    print("正在保存" + filename)
    with open(filename, "w", encoding = "utf-8") as file:
        file.write(html)
    print("-" *30)

def tiebaspider(url, beginpage, endpage):
    for page in range(beginpage, endpage + 1):
        pn = (page - 1) * 50
        filename = "第" + str(page) + "页.html"
        fullurl = url + "&pn" + str(pn)
        print(fullurl)
        html = loadPage(fullurl, filename)
        print("网站内容：", html)
        writePage(html, filename)
        print("谢谢使用")
if __name__ == "__main__":
    kw = input("请输入需要爬取的贴吧名:")
    beginPage = int(input("请输入起始页："))
    endPage = int(input("请输入结束页："))
 
    url = "http://tieba.baidu.com/f?"
    key = parse.urlencode({"kw": kw}) #.encode("utf-8")
    fullurl = url + key
    tiebaspider(fullurl, beginPage, endPage)
    # print(parse.urlencode("关于Python在"))
    print("key",key)
    print(parse.urlencode({"kw":"除了web开发以外，还有其他吗？"}))
html = urlopen("http://tieba.baidu.com/f?kw=python&pn=100")
print(html.read().decode("utf-8"))

