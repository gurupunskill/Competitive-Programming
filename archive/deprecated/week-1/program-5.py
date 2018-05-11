#!/bin/python3
# https://www.hackerrank.com/challenges/picking-numbers/problem
import sys
from collections import Counter

n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]

maxn = max(a) +1
freq_a = [0 for i in range(0,maxn)]
for i in a:
    freq_a[i]+=1

maxcf = freq_a[0] + freq_a[1]
for i in range(2,maxn):
    newcf = freq_a[i] + freq_a[i-1]
    if newcf > maxcf:
        maxcf = newcf

print(maxcf)
