#!/usr/bin/env python3

MIN_LENGTH = 1
MAX_LENGTH = 10**3

s = input()
t = input()
assert all(c in 'bB' for c in s)
assert all(c in 'bB' for c in t)
assert MIN_LENGTH <= len(s) <= MAX_LENGTH
assert MIN_LENGTH <= len(t) <= MAX_LENGTH
