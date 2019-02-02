#!/usr/bin/env python3
k = int(input())
y, x = map(int, input().split())

if y % 2 == 1:
    idx = k*(y-1) + x
else:
    idx = k*(y-1) + (k-x+1)
chars = ['y', 'f', 'k', 'p', 'o']
print(chars[(idx-1) % 5])
