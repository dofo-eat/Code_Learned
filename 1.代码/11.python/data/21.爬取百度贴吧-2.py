#!/usr/bin/env python
# coding=utf-8
"""爬百度贴吧"""

import requests
import re

class TiebaSpider:
    """贴吧爬虫"""
    def __init__(self):
        """初始化参数"""
        self.kw = input('关键词：')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        self.header = {"User-Agent" : "Mozilla/5.0 (Macintosh;\
                       Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14"}
        self.title = ''

    def parse_text(self, url, params = None):
        """发送请求，获取响应内容"""
        req = requests.get(url, headers = self.header, params = params)
        return req.text#响应对象的文本信息

    def parse_byte(self, url, params = None):
        req = requests.get(url, headers = self.header, params = params)
        return req.content#响应对象的content

    def page(self, content):
        """解析每一页"""
        print("第{}页爬取中...".format(self.page_num))
        self.page_num += 1
        pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
        url_title = pattern.findall(content)
        for url, title in url_title:
            self.title = title
            self.detail('https://tieba.baidu.com' + url)
            #保存标题
            self.save_title()
            #判断下一页
            next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', content)
        if next_url:#下一页存在
            next_url = 'https:' + next_url[0]
            content = self.parse_text(url = next_url)
            self.page(content)
        else:
            print('爬虫结束...共爬取{}页！'.format(self.page_num))

    def detail(self, url):
        """每一个帖子的详情"""
        content = self.parse_text(url = url)
        urls = re.findall(r'<img class="BDE_Image".*?src="(.*?)".*?', content)
        for url in urls:
            self.save_img(url = url)

    def save_title(self):
        """保存帖子的标题"""
        with open('./data/tieba/tieba_{}.txt'.format(self.kw), 'a', encoding = 'utf-8') as file:
            file.write(self.title)
            file.write('\n')

    def save_img(self, url):
        """保存图片"""
        content = self.parse_byte(url = url)
        image_path = './data/tieba/images/{}.jpg'.format(self.title)
        try:
            with open(image_path, 'wb') as file:
                file.write(content)
        except:
            pass

    def start(self):
        """开始爬虫"""
        print('爬虫开始...')
        content = self.parse_text(url = self.base_url, params = {'kw' : self.kw, 'ie' : 'utf-8', 'fr' : 'search'})
        self.page(content)

if __name__ == '__main__':
    spider = TiebaSpider()
    spider.start()
    

