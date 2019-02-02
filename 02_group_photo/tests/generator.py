#!/usr/bin/env python3
from collections import namedtuple
import random

NUM_TESTCASE = 40

MAX_K = 500
MIN_K = 1
MAX_Y = 500
MIN_Y = 1
MAX_X = 500
MIN_X = 1

Case = namedtuple('Case', ('K', 'Y', 'X'))


def generate_case():
    k = random.randint(MIN_K, MAX_K)
    y = random.randint(MIN_Y, MAX_Y)
    x = random.randint(MIN_X, min(MAX_Y, k))

    return Case(k, y, x)


def main():
    testcases = set()
    testcases.add(Case(6, 4, 2))
    testcases.add(Case(2, 3, 2))
    testcases.add(Case(MIN_K, MIN_Y, MIN_X))
    testcases.add(Case(MAX_K, MAX_Y, MAX_X))
    testcases.add(Case(MAX_K-1, MAX_Y, MAX_X-2))
    testcases.add(Case(MAX_K-2, MAX_Y-1, MAX_X-3))

    size_testcase = len(testcases)
    while size_testcase < NUM_TESTCASE:
        testcase = generate_case()
        if testcase not in testcases:
            testcases.add(testcase)
            size_testcase += 1

    for i, (k, y, x) in enumerate(list(testcases)):
        with open('input_{}.in'.format(i), 'w') as fout:
            fout.write('{}\n{} {}\n'.format(k, y, x))


if __name__ == "__main__":
    main()
