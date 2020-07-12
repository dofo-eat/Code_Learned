#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
a = int(input("a 值："))
b = int(input("b 值："))

print(gcd(a, b))


