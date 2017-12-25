#!/bin/python3
# https://www.hackerrank.com/challenges/reduced-string/problem
import sys

def super_reduced_string(s):
    # Complete this function
    flag = 1
    while (flag != 0):
        flag = 0
        i = 0
        n = len(s)
        while(i < n-1):
            if s[i] == s[i+1]:
                del s[i]
                del s[i]
                flag = 1
                n -= 2
            i += 1

    s = ''.join(s)
    if ( s == "" ):
        s = "Empty String"
    return s

s = list(input().strip())
result = super_reduced_string(s)
print(result)
