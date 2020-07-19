#!/usr/bin/env python
# coding=utf-8

from selenium import webdriver
import json
import time
import os
class CodeSpaider:
    url = ""
    cookie_file = './cookie_file'
    data_path = './jisuanke/'
    lesson_name = ''
    lesson_url = []
    num = 0
    course = {'数据结构': 792}

    def __init__(self, lesson_name = "数据结构", url = "https://www.jisuanke.com/course/792"):
        print('__init__')
        self.lesson_name = lesson_name
        self.url = url
        driver = webdriver.Chrome()
        driver.set_page_load_timeout(60)
        driver.get("www.jisuanke.com")

        with open(self.cookie_file, 'r') as file:
            cookies = json.load(file)
            for cookie in cookies:
                driver.add_cookie(cookie)

        driver.get(self.url)
        time.sleep(3)
        self.driver = driver

    #def get_url(self):
    #def get_code(self):
    #def save_code(self):
    #def destroy(self):



if __name__ == "__main__":
    test = CodeSpaider()
