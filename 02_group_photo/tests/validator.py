#!/usr/bin/env python3
MAX_K = 500
MIN_K = 1
MAX_Y = 500
MIN_Y = 1
MAX_X = 500
MIN_X = 1

k = int(input())
assert MIN_K <= k <= MAX_K
y,x = map(int, input().split())
assert MIN_Y <= y <= MAX_Y
assert MIN_X <= x <= k <= MAX_X

