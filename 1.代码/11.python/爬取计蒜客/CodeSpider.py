 
#!/usr/bin/env python
# coding=utf-8

from selenium import  webdriver
import time
import os
import json

class CodeSpider:
    url = ""
    cookie_file = './cookie_file1'
    data_path = './data'
    lesson_name = ''
    lesson_url = []
    num = 0
    course = {
        'C语言' : 786, '系统编程' : 791, '数据结构' : 792,  '求职算法' : 799,
        '面向对象' : 790, 'Python' : 788, 'C++' : 787
    }

    def __init__(self, lesson_name = "数据结构", url = "https://www.jisuanke.com/course/792"):
        print('__init__')
        self.lesson_name = lesson_name
        self.url = url
        driver = webdriver.Chrome()
        driver.set_page_load_timeout(30)
        driver.get("https://www.jisuanke.com")

        with open(self.cookie_file, "r") as f:
            cookies = json.load(f)
            for cookie in cookies:
                driver.add_cookie(cookie)

        driver.get(self.url)
        time.sleep(3)
        self.driver = driver


    def gen_url(self):
        self.driver.refresh()
        chapters = self.driver.find_elements_by_css_selector("[class='jsk-list jsk-list-striped lessons']")
        for x in chapters:
            lessons = x.find_elements_by_tag_name('li')
            for y in lessons:
                spans = y.find_elements_by_tag_name('span')
                if spans[0].get_attribute('title') == '已完成' and spans[0].get_attribute('class') == "lesson-icon-challenge":
                    self.lesson_url.append({"name": spans[1].get_attribute('title'), "url": y.find_element_by_tag_name('a').get_attribute('data-url')})

    def save_code(self, num, filename, url):
        js_code = "window.open(\"%s\")" % url
        self.driver.execute_script(js_code)
        handles = self.driver.window_handles
        self.driver.switch_to.window(handles[1])
        code = self.driver.find_element_by_tag_name('pre')
        file_path = "%s/%s" % (self.data_path, self.lesson_name)
        if not os.path.exists(file_path):
            os.makedirs(file_path)
        file_path = "%s/%d.%s.c" % (file_path, num, filename)

        with open(file_path, 'w') as f:
            f.write(code.text)
            f.write('\n')
            f.close()

        self.driver.close()
        self.driver.switch_to.window(handles[0])


    def get_code(self):
        cnt = 0;
        for i in self.lesson_url:
            print(i['url'])
            self.driver.get("https:"+i['url'])
            time.sleep(1)
            continue_ = self.driver.find_elements_by_css_selector('[class="jsk-btn jsk-link-muted"]')
            if len(continue_):
                continue_[0].click()
            time.sleep(1)
            his = self.driver.find_elements_by_css_selector('[class="jsk-btn jsk-margin-right jsk-btn-default"]')
            his[0].click()
            time.sleep(1)
            submit_list = self.driver.find_element_by_tag_name('tbody')
            for x in submit_list.find_elements_by_tag_name('tr'):
                success_list = x.find_elements_by_css_selector('[class="jsk-text-success"]')
                if len(success_list):
                    code_url = x.find_element_by_tag_name('a').get_attribute('href')
                    cnt = cnt + 1
                    break
            self.save_code(cnt, i['name'], code_url)



    def destroy(self):
        self.driver.quit()

    def auto(self):
        self.gen_url()
        self.get_code()
        self.destroy()

    def __del__(self):
        print('__del__')

