#!/usr/bin/env python3
n, k = map(int, input().split())
f = list(map(int, input().split()))
b = list(map(int, input().split()))

assert 1 <= n <= 100000
assert 0 <= k <= 100000
assert all(1 <= fi <= 100000 for fi in f)
assert all(1 <= bi <= 100000 for bi in b)
