#!/usr/bin/env python3

from collections import namedtuple
import random

NUM_TESTCASE = 40

MAX_N = 2*10**2
MIN_N = 1
MAX_C = 10
MIN_C = 1

Case = namedtuple('Case', ('N', 'G'))


def generate_graph(n):
    graph = [(0,)]
    for i in range(1,n):
        row = []
        for j in range(i+1):
            row.append(random.randint(MIN_C, MAX_C))
        if i == n-1:
            row[0] = 0
            row[n-1] = 0
        graph.append(tuple(row))
    return Case(
        n,
        tuple(graph)
    )


def main():
    testcases = set()
    testcases.add(
        Case(
            3,
            (
                (0,),
                (4, 1),
                (0, 2, 0)
            )
        )
    )
    testcases.add(
        Case(
            5,
            (
                (0,),
                (9, 1),
                (9, 1, 9),
                (1, 5, 1, 1),
                (0, 1, 1, 9, 0),
            )
        )
    )
    size_testcase = len(testcases)
    while size_testcase < NUM_TESTCASE:
        n = random.randint(MIN_N, MAX_N)
        testcase = generate_graph(n)
        if testcase not in testcases:
            testcases.add(testcase)
            size_testcase += 1

    for i, (n, g) in enumerate(list(testcases)):
        with open('input_{}.in'.format(i), 'w') as fout:
            fout.write('{}\n'.format(n))
            for row in g:
                fout.write('{}\n'.format(' '.join(map(str, row))))


if __name__ == "__main__":
    main()
