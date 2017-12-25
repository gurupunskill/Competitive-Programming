#!/bin/python3
# https://www.hackerrank.com/challenges/the-birthday-bar/problem
# O(n)
import sys

def solve(n, s, d, m):

    csum = sum(s[0:m])
    count = 0
    if ( n == 1 ):
        if ( csum == d ):
            return 1
        else:
            return 0
    for i in range(m,n):
        if ( csum == d ):
            count += 1
        csum -= s[i-m]
        csum += s[i]

    if ( csum == d ):
        count += 1
    return count
n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
d, m = input().strip().split(' ')
d, m = [int(d), int(m)]
result = solve(n, s, d, m)
print(result)
