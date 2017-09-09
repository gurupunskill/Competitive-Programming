#!/bin/python3
# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

import sys

n = int(input().strip())
scores = [int(scores_temp) for scores_temp in input().strip().split(' ')]
m = int(input().strip())
alice = [int(alice_temp) for alice_temp in input().strip().split(' ')]


rank = [ 1 for i in range(n)]
for i in range(1,n):
    if scores[i] < scores[i-1]:
        rank[i] = rank[i-1] + 1
    elif scores[i] == scores[i-1]:
        rank[i] = rank[i-1]

for i in range(0,m):
    while ( n > 0 and alice[i] >= scores[n-1] ):
        scores.pop()
        n-=1
    if ( n <= 0 ):
        print(1)
        continue
    print(rank[n-1]+1)
