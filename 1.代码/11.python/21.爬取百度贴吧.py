#!/usr/bin/env python
# coding=utf-8

import requests
import re

#贴吧爬虫
class TiebaSpider:
    def __init__(self):
        #初始化参数
        self.kw = input('关键词')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1;
        #把自己伪装成浏览器(伪装头)
        self.header = {"User-Agent":"Mozilla/5.0 (Windows NT 5.1) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.84 Safari/535.11 SE 2.X MetaSr 1.0 "}
        self.title = self.base_url + self.kw

    def parse_text(self, url, params = None):
        #发送请求， 获取响应内容
        response = requests.get(url, header = self.header, params = params)
        return response.text#响应对象的文本信息

    def parse_byte(self, url, params = None):
        #解析图片
        response = requests.get(url, header = self.header, params = params)
        return req.text #响应对象的文本信息

    def page(self, content):
        #解析每一页
        print("第{}页爬取中".format(self.page_num))
        #获取标题， 保存标题
        self.page_num += 1
        pattern = re.compile(r'<a rel="noreferrer" herf="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
        url_title
        for url, title in url_title:
            self.title = title
            self.detail('https://tieba.baidu.com/f' + url)
            self.save_title()
        #处理图片
        #判断下一页
        #调用下一页的
        next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', str)
        if next_url:
            next_url = "https:" + next_url[0]
            content = self.parse_text(url)
        else:
            print('结束...爬取了{}页'.format(self.page_num))
    def save_title(self, page):
        with open('./data/tieba/tieba_{}.txt'.format(self.kw), 'a', encoding = 'utf-8') as file:
            file.write(self.title)
            file.write('\n')
    
    def save_img(self, url):
        #获取图片
        content = self.base_url(url = url)
        image_path = './data/tieba/images/{}.jpg'.format(self.title)
        with open (image_path, 'wb') as file
        file.write()
    def start(self):
        #开始爬虫
        print("爬虫开始...")
        #返回当前这一页的内容
        content = self.parse_text(url = self.base_url, params = {'kw':self.kw, 'ie':'utf-8', 'fr':'search'})
        self.page(content)

if __name__ == '__main__':
    spider = TieBaSpider()
    spider.start()


