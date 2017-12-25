#! usr/bin/python

import sys
import statistics as stat

def activityNotifications(expenditure, d):
    # Complete this function
    j = 0
    count = 0
    for i in range(d, len(expenditure)):
        med = stat.median(expenditure[j:i])
        if expenditure[i] >= 2*med:
            count += 1
        j += 1
    return count

if __name__ == "__main__":
    n, d = input().strip().split(' ')
    n, d = [int(n), int(d)]
    expenditure = list(map(int, input().strip().split(' ')))
    result = activityNotifications(expenditure, d)
    print(result)