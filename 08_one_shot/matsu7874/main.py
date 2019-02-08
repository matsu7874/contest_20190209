#!/usr/bin/env python3

import collections

n, k = map(int, input().split())
k = min(n, k)
f = list(map(int, input().split()))
b = list(map(int, input().split()))


max_bi = collections.deque()
max_bi.append(0)

max_v = 0

bi = 1

for fi in range(n):
    while bi < n and bi <= fi+k:
        while max_bi and b[max_bi[-1]] <= b[bi]:
            max_bi.pop()
        max_bi.append(bi)
        bi += 1
    while max_bi and max_bi[0] < fi-k:
        max_bi.popleft()

    max_v = max(max_v, f[fi] + b[max_bi[0]])
print(max_v)