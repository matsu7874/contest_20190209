#!/usr/bin/env python3
import collections
n, d = map(int, input().split())
d2 = d**2
stations = []
for i in range(n):
    y, x = map(int, input().split())
    stations.append((y, x))

graph = [[] for _ in range(n)]
for i in range(n-1):
    iy, ix = stations[i]
    for j in range(i+1, n):
        jy, jx = stations[j]
        if (iy-jy)**2+(ix-jx)**2 <= d2:
            graph[i].append(j)
            graph[j].append(i)

count = [0 for i in range(n)]
prev = [-1 for i in range(n)]
dq = collections.deque()

for nv in graph[0]:
    dq.append(nv)
    count[nv] += 1
    prev[nv] = 0

while dq:
    v = dq.popleft()
    if count[v] > 1:
        continue
    for nv in graph[v]:
        if nv == prev[v]:
            continue
        count[nv] += 1
        if count[nv] > 1:
            continue
        prev[nv] = v
        dq.append(nv)
    
path = [n-1]
while path[-1] != 0:
    path.append(prev[path[-1]])
for v in path[::-1]:
    print(v+1)
