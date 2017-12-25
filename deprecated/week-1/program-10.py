#!/bin/python3

import sys
from math import ceil, sqrt

s = input().strip()
l = ceil(sqrt(len(s)))
print(' '.join(map(lambda x: s[x::l], range(l))))
