#!/bin/python3
# Question: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
# O(n)
import sys

# Attempt 1:
def getRecord(s):
    highest = s[0]
    lowest = s[0]
    high_count = 0
    low_count = 0

    for i in s:
        if i > highest:
            high_count += 1
            highest = i
        if i < lowest:
            low_count += 1
            lowest = i

    return high_count, low_count

n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
result = getRecord(s)
print (" ".join(map(str, result)))
