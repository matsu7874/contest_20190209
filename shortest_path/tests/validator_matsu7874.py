#!/usr/bin/env python3

n, m = map(int, input().split())
assert 2 <= n <= 10**4
assert 1 <= m <= 10**4
edges = set()
for i in range(m):
    s, t, c = map(int, input().split())
    assert 1 <= s < t <= n, '1 <= {} < {} <= {}'.format(s, t, n)
    assert 1 <= c <= 10**5, '1 <= {} <= 10**5'.format(c)
