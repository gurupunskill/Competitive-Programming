#!/bin/python3
# https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
# O(n)
import sys

def divisibleSumPairs(n, k, ar):
    count = 0
    mods = [0 for i in range(0,k)]
    for i in ar:
        mods[i%k] += 1
    for i in ar:
        if (i%k == 0):
            count += mods[0]
            count -= 1
        else:
            count += mods[k-(i%k)]
        if ( i%k == (k-(i%k))):
            count -= 1
    return int(count/2)


n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
ar = list(map(int, input().strip().split(' ')))
result = divisibleSumPairs(n, k, ar)
print(result)
