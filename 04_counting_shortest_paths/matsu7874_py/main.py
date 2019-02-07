#!/usr/bin/env python3
import heapq

mod = 10**9+7

def main():
    n, m = map(int, input().split())
    graph = [[] for i in range(n)]
    for _ in range(m):
        s, t, c = map(int, input().split())
        graph[s-1].append((t-1, c))
        graph[t-1].append((s-1, c))

    cnt = [0 for i in range(n)]
    dist = [float('inf') for i in range(n)]
    cnt[0] = 1
    hq = [(0, 0, 0)]
    while hq:
        d, v, pv = heapq.heappop(hq)
        # print(d,v,pv)
        if d > dist[v]:
            continue
        elif d == dist[v]:
            cnt[v] += cnt[pv]
        else:
            dist[v] = d
            cnt[v] = cnt[pv]
            for nv, c in graph[v]:
                if d + c > dist[nv]:
                    continue
                heapq.heappush(hq, (d+c, nv, v))
    # print(graph)
    # print(dist)
    # print(cnt)
    print(cnt[n-1] % mod)


if __name__ == "__main__":
    main()
