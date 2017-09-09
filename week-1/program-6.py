#!/bin/python3
# Program 6: https://www.hackerrank.com/challenges/save-the-prisoner/problem

import sys

def saveThePrisoner(n, m, s):
    # Complete this function
    k = (s + m - 1)%n
    if ( k == 0):
        return(n)
    return(k)
t = int(input().strip())
for a0 in range(t):
    n, m, s = input().strip().split(' ')
    n, m, s = [int(n), int(m), int(s)]
    result = saveThePrisoner(n, m, s)
    print(result)
