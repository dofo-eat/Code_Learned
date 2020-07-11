#!/usr/bin/env python
# coding=utf-8
max_n = 1000
prime = [0 for i in range(max_n + 5)]

for i in range(2, max_n):
    if  prime[i] == 0:
        prime[0] = prime[0] + 1
        prime[prime[0]] = i
    for j in range(1, prime[0] + 1):
        if prime[j] * i > max_n:
            break
        else:
            prime[prime[j] * i] = 1
        if i % prime[j] == 0:
            break
print(prime)
#print(prime[0:])
#for i in range(1, prime[0] + 1):
 #   print(prime[i])
