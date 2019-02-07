#!/usr/bin/env python3
MAX_N = 2*10**2
MIN_N = 1
MAX_C = 10
MIN_C = 1

n = int(input())
assert MIN_N <= n <= MAX_N

graph = []
for i in range(n):
    graph.append(list(map(int, input().split())))

assert len(graph) == n
assert graph[0][0] == 0
assert graph[n-1][0] == 0
assert graph[n-1][n-1] == 0

for i in range(n):
    assert len(graph[i]) == i+1

for i in range(1, n-1):
    for c in graph[i]:
        assert MIN_C <= c <= MAX_C
for c in graph[n-1][1:-1]:
    assert MIN_C <= c <= MAX_C
