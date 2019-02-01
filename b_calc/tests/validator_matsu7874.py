#!/usr/bin/env python3

MIN_LENGTH = 1
MAX_LENGTH = 50

s = input()
t = input()
assert all(c in 'bB' for c in s)
assert all(c in 'bB' for c in t)
assert s == 'b' or s[0] == 'B'
assert t == 'b' or t[0] == 'B'
assert MIN_LENGTH <= len(s) <= MAX_LENGTH
assert MIN_LENGTH <= len(t) <= MAX_LENGTH
