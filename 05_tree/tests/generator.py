#!/usr/bin/env python3
from collections import namedtuple
import random

NUM_TESTCASE = 40

MAX_NODE = 10**5
MIN_NODE = 1

Case = namedtuple('Case', ('N', 'G'))


def generate_graph(num_node):
    edges = []
    for i in range(num_node-1):
        edges.append(random.randint(0, i))
    return Case(
        num_node,
        tuple(edges)
    )


def generate_graph_uni(num_node):
    return Case(
        num_node,
        tuple(1 if i > 0 else 0 for i in range(num_node-1))
    )


def generate_graph_liner(num_node):
    return Case(
        num_node,
        tuple(i for i in range(num_node-1))
    )


def main():
    testcases = set()
    testcases.add(
        Case(
            3,
            (0, 1)
        )
    )
    testcases.add(generate_graph_uni(6))
    testcases.add(generate_graph_uni(MAX_NODE))
    testcases.add(generate_graph_liner(6))
    testcases.add(generate_graph_liner(MAX_NODE))
    size_testcase = len(testcases)
    while size_testcase < NUM_TESTCASE:
        num_node = random.randint(MIN_NODE, MAX_NODE)
        testcase = generate_graph(num_node)
        if testcase not in testcases:
            testcases.add(testcase)
            size_testcase += 1

    for i, (n, g) in enumerate(list(testcases)):
        with open('input_{}.in'.format(i), 'w') as fout:
            fout.write('{}\n'.format(n))
            for p in g:
                fout.write('{}\n'.format(p))


if __name__ == "__main__":
    main()
