#!/usr/bin/env python3
import collections
import sys

MAX_N = 10**3
MIN_N = 2
MAX_D = 10**2
MIN_D = 1
MAX_Y = 10**5
MIN_Y = 0
MAX_X = 10**5
MIN_X = 0

sys.setrecursionlimit(MAX_N + 10)

n, d = map(int, input().split())
assert MIN_N <= n <= MAX_N
assert MIN_D <= d <= MAX_D
stations = []
for i in range(n):
    y,x = map(int, input().split())
    assert MIN_Y <= y <= MAX_Y
    assert MIN_X <= x <= MAX_X
    stations.append((y,x))
assert len(stations) == n
assert len(set(stations)) == n

graph = [[] for i in range(n)]
for i in range(n-1):
    for j in range(i+1, n):
        iy, ix = stations[i]
        jy, jx = stations[j]
        if (iy-jy)**2+(ix-jx)**2 <= d**2:
            graph[i].append(j)
            graph[j].append(i)

# 0 --> N-1の経路ただ1つだけ存在する ⇔ 0 -- N-1に閉路がない
visited = [0] * n
prev = [-1] * n

def dfs(v):
    visited[v] += 1
    if visited[v] > 1:
        return False

    if v == n-1:
        return True

    for nv in graph[v]:
        if nv == prev[v]:
            continue
        if visited[nv] > 0:
            return False
        prev[nv] = v
        if not dfs(nv):
            return False
    return True

visited[0] = 1
for nv in graph[0]:
    pre_visited = visited[n-1]
    prev[nv] = 0
    res = dfs(nv)
    assert visited[n-1] - pre_visited == 0 or visited[n-1] == 1
assert visited[n-1] == 1
