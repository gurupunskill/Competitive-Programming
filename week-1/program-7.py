#!/bin/python3
# Program 7: https://www.hackerrank.com/challenges/utopian-tree/problem
import sys


t = int(input().strip())
for a0 in range(t):
    h = 1
    k = 1
    n = int(input().strip())

    q = n//2
    r = (n%2)

    h = (2**(q+1)) -1
    h = h + r*h
    print(h)
