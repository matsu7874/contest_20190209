#!/usr/bin/env python3
from collections import namedtuple
import random
NUM_TESTCASE = 40

Case = namedtuple('Case', ('N', 'S', 'T'))

N_MIN = 2
N_MAX = 100
S_MIN = 1
S_MAX = 10000
T_MIN = 1
T_MAX = 10000
"""
2 <= N <= 100
1 <= S_1 <= 10000
T_1 = 0
i >= 2について1 <= T_i < S_i <= 10000
"""
testcases = set()

testcases.add(Case(
    5,
    (24,24,23,14,52),
    (0,12,18,6,16)
))
size_testcase = len(testcases)

while size_testcase < NUM_TESTCASE:
    n = random.randint(N_MIN, N_MAX)
    s = [random.randint(S_MIN, S_MAX)]
    t = [0]
    for i in range(n-1):
        si = random.randint(S_MIN+1, S_MAX)
        ti = random.randint(T_MIN, min(T_MAX, si-1))
        s.append(si)
        t.append(ti)
    s = tuple(s)
    t = tuple(t)
    if Case(n, s, t) not in testcases:
        testcases.add(Case(n, s, t))
        size_testcase += 1

for i, (n, s, t) in enumerate(list(testcases)):
    with open('input_{}.in'.format(i), 'w') as fout:
        s_str = ' '.join(map(str, s))
        t_str = ' '.join(map(str, t))
        fout.write('{}\n{}\n{}\n'.format(str(n), s_str, t_str))
