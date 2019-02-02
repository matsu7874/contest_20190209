#!/usr/bin/env python3
import functools
n = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))


@functools.lru_cache(maxsize=None)
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a


for i in range(n):
    diff = s[i]-t[i]
    numerator = diff // gcd(diff, s[0])
    denominator = (s[0]) // gcd(diff, s[0])
    print(numerator, denominator)
