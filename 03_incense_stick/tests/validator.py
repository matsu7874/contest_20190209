#!/usr/bin/env python3
"""
2 <= N <= 100
1 <= S_1 <= 10000
T_1 = 0
i >= 2について1 <= T_i < S_i <= 10000
"""

n = int(input())
assert 2 <= n <= 100

s = list(map(int, input().split()))
assert len(s) == n

t = list(map(int, input().split()))
assert len(t) == n
assert t[0] == 0

for i in range(1, n):
    assert 1 <= t[i] < s[i] <= 10000, "{} {}".format(t[i], s[i])