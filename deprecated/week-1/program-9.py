# https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
#!/bin/python3

import sys

q = int(input().strip())
for a0 in range(q):
    n = int(input().strip())
    M = []
    for M_i in range(n):
        M_temp = list(map(int,input().split(' ')))
        M.append(M_temp)

    ### O(nlogn)
    column_sums = sorted([sum([row[i] for row in M]) for i in range(0,len(M[0]))])
    row_sums = sorted([sum(row) for row in M])
    flag = True

    ### O(n)
    for i in range(0,n):
        if (column_sums[i] != row_sums[i]):
            flag = False
            print ("Impossible")
            break
    if (flag):
        print("Possible")
