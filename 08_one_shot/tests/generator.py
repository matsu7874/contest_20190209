#!/usr/bin/env python3
from collections import namedtuple
import random
NUM_TESTCASE = 40

Case = namedtuple('Case', ('N', 'K', 'F', 'B'))

N_MIN = 1
N_MAX = 100000
K_MIN = 0
K_MAX = 100000
F_MIN = 1
F_MAX = 100000
B_MIN = 1
B_MAX = 100000
"""
1 <= N <= 100000
0 <= K <= 100000

1 <= F_i <= 100000
1 <= B_i <= 100000
"""
testcases = set()

testcases.add(Case(
    4, 1,
    (1, 3, 4, 5),
    (4, 2, 1, 1)
))

testcases.add(Case(
    N_MAX, K_MIN,
    (F_MIN+i for i in range(N_MAX)),
    (B_MAX-i for i in range(N_MAX)),
))

testcases.add(Case(
    N_MAX, K_MIN,
    (F_MAX-i for i in range(N_MAX)),
    (B_MAX-i for i in range(N_MAX)),
))

size_testcase = len(testcases)

while size_testcase < NUM_TESTCASE:
    n = random.randint(N_MIN, N_MAX)
    k = random.randint(K_MIN, K_MAX)
    f = (random.randint(F_MIN, F_MAX) for _ in range(n))
    b = (random.randint(B_MIN, B_MAX) for _ in range(n))
    if Case(n, k, f, b) not in testcases:
        testcases.add(Case(n, k, f, b))
        size_testcase += 1

for i, (n, k, f, b) in enumerate(list(testcases)):
    with open('input_{}.in'.format(i), 'w') as fout:
        f_str = ' '.join(map(str, f))
        b_str = ' '.join(map(str, b))
        fout.write('{} {}\n{}\n{}\n'.format(str(n), str(k), f_str, b_str))
