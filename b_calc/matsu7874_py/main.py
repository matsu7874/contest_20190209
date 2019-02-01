#!/usr/bin/env python3

s = input()
t = input()


def b2i(b):
    res = 0
    for c in b:
        res *= 2
        if c == 'B':
            res += 1
    return res


def i2b(i):
    res = []
    n = 2
    len_i = 1
    while n <= i:
        n <<= 1
        len_i += 1
    res = ['b'] * len_i
    for j in range(len_i):
        n >>= 1
        if i >= n:
            res[j] = 'B'
            i -= n
    return ''.join(res)


def add(s, t):
    return i2b(b2i(s) + b2i(t))


print(add(s, t))
