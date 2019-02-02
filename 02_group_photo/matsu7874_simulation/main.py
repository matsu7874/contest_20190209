#!/usr/bin/env python3
k = int(input())
y, x = map(int, input().split())


cells = [[''] * k for _ in range(y)]
chars = ['y', 'f', 'k', 'p', 'o']
len_chars = len(chars)
idx = 0
for i in range(y):
    if i % 2 == 0:
        for j in range(k):
            cells[i][j] = chars[idx]
            idx = (idx+1) % len_chars
    else:
        for j in range(k-1, -1, -1):
            cells[i][j] = chars[idx]
            idx = (idx+1) % len_chars
print(cells[y-1][x-1])