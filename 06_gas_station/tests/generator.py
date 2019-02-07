#!/usr/bin/env python3

from collections import namedtuple
import functools
import random

NUM_TESTCASE = 40

MAX_N = 10**3
MIN_N = 2
MAX_D = 10**2
MIN_D = 1
MAX_Y = 10**5
MIN_Y = 0
MAX_X = 10**5
MIN_X = 0

Case = namedtuple('Case', ('I', 'N', 'D', 'G'))


def main():
    testcases = set()
    testcases.add(
        Case(
            0,
            3, 1,
            (
                (0, 0),
                (1, 0),
                (1, 1),
            )
        )
    )
    testcases.add(
        Case(
            1,
            7, 3,
            (
                (5, 5),
                (2, 2),
                (4, 1),
                (2, 5),
                (5, 6),
                (10, 10),
                (0, 0),
            )
        )
    )
    testcases.add(
        Case(
            2,
            2, 1,
            (
                (5, 5),
                (5, 6),
            )
        )
    )
    testcases.add(
        Case(
            3,
            MAX_N, MAX_D,
            ((i*MAX_D, 0) for i in range(MAX_N))
        )
    )
    d = int(MAX_D*0.8)
    testcases.add(
        Case(
            4,
            MAX_N, d,
            ((i*int(d/(2**0.5)), i*int(d/(2**0.5))) for i in range(MAX_N))
        )
    )
    testcases.add(
        Case(
            5,
            MAX_N, MAX_D,
            ((0, i*MAX_D) for i in range(MAX_N))
        )
    )
    testcases.add(
        Case(
            6,
            MAX_N, MAX_D,
            ((0, i*(MAX_D-1)+i % 2) for i in range(MAX_N))
        )
    )
    graph = []
    for i in range(31):
        for j in range(31):
            graph.append((100-i, 200-j))
    graph.extend([(100, 300), (200, 300), (300, 300)])
    graph.extend([(300, 0), (300, 100), (300, 200)])
    graph.extend([(200, 0), (100, 0), (0, 0)])
    testcases.add(
        Case(7, len(graph), MAX_D, tuple(graph))
    )

    # size_testcase = len(testcases)
    # while size_testcase < NUM_TESTCASE:
    #     n = random.randint(MIN_N, MAX_N)
    #     testcase = generate_graph(n)
    #     if testcase not in testcases:
    #         testcases.add(testcase)
    #         size_testcase += 1

    for i, n, d, g in list(testcases):
        with open('input_{}.in'.format(i), 'w') as fout:
            fout.write('{} {}\n'.format(n, d))
            for y, x in g:
                fout.write('{} {}\n'.format(y, x))


if __name__ == "__main__":
    main()
