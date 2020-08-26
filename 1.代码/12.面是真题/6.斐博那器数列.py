#!/usr/bin/env python
# coding=utf-8

n = int(input())
lis = [1, 1]
for i in range(1, n):
    lis.append(lis[-1] + lis[-2])
print(lis[n])
