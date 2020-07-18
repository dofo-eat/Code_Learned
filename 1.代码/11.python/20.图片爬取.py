#!/usr/bin/env python
# coding=utf-8

import requests

src = "http://tiebapic.baidu.com/forum/w%3D580%3B/sign=260e1f45c51b0ef46ce89856edff50da/aec379310a55b3196908d51e54a98226cefc17e3.jpg"

response = requests.get(src)
with open('./data/tieba/images/1.jpg', 'wb') as file:
    file.write(response.content)
