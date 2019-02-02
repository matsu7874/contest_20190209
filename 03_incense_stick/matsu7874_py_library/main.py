#!/usr/bin/env python3
import fractions
n = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))

for i in range(n):
    ret = fractions.Fraction(s[i]-t[i], s[0])
    print(ret.numerator, ret.denominator)
