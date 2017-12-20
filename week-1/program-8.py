# https://www.hackerrank.com/challenges/non-divisible-subset/problem

# For every mod, there exists only one other mod ehose sum will make it divisible
# So you can add the elements of only one of that mod pair
# You can add only one element of mod0
# If i = k=i, You can add only one element of modi
# This is the middle case with no unique pair.

n,k = input().strip().split(' ')
n,k = [int(n),int(k)]
a = [int(a_temp) for a_temp in input().strip().split(' ')]

mods = [0 for i in range(0,k)]
for i in a:
    mods[i%k] += 1

maxs = min(mods[0],1)
for i in range(1,k//2 +1):
    if ( i != k - i):
        maxs += max(mods[i],mods[k-i])
    else:
        maxs += 1

print(maxs)
