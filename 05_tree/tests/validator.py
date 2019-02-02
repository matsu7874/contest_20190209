#!/usr/bin/env python3

MAX_NODE = 10**5
MIN_NODE = 1


n = int(input())
parents = [int(input()) for i in range(n-1)]

assert MIN_NODE <= n <= MAX_NODE

assert len(parents) == n-1

for i in range(n-1):
    assert parents[i] <= i
