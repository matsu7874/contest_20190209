#!/usr/bin/env python3
from collections import namedtuple
import random

NUM_TESTCASE = 40

MAX_NODE = 10**4
MIN_NODE = 2

MAX_EDGE = 10**4
MIN_EDGE = 1

MAX_COST = 10**5
MIN_COST = 1

Case = namedtuple('Case', ('N', 'M', 'G'))


def generate_graph(num_node, num_edge, max_cost):
    cnt_edge = 0
    edges = []
    while cnt_edge < num_edge:
        s = random.randint(1, num_node)
        t = random.randint(1, num_node)
        if s == t:
            continue
        s, t = min(s, t), max(s, t)

        edges.append((s, t, random.randint(MIN_COST, max_cost)))
        cnt_edge += 1
    edges.sort()
    return Case(
        num_node,
        num_edge,
        tuple(edges)
    )


def generate_graph_strong(num_node):
    cnt_edge = 0
    edges = []
    for i in range(num_node-1):
        for j in range(i+1, num_node):
            edges.append((i+1, j+1, j-i))
            cnt_edge += 1
    edges.sort()
    return Case(
        num_node,
        cnt_edge,
        tuple(edges)
    )


def main():
    testcases = set()
    testcases.add(
        Case(4, 5, (
            (1, 2, 3),
            (2, 3, 3),
            (1, 4, 5),
            (2, 4, 2),
            (1, 3, 3),
        ))
    )
    testcases.add(
        Case(3, 1, (
            (1, 2, 1),
        ))
    )
    testcases.add(
        Case(4, 3, (
            (1, 3, 1),
            (2, 3, 1),
            (2, 4, 1),
        ))
    )
    testcases.add(generate_graph_strong(5))
    testcases.add(generate_graph(5, MAX_EDGE, 1))
    testcases.add(generate_graph_strong(int(MAX_EDGE**0.5)))
    size_testcase=len(testcases)
    while size_testcase < NUM_TESTCASE:
        num_node=random.randint(MIN_NODE, MAX_NODE)
        num_edge=random.randint(MIN_EDGE, MAX_EDGE)
        max_cost=random.randint(MIN_COST, MAX_COST)
        testcase=generate_graph(num_node, num_edge, max_cost)
        if testcase not in testcases:
            testcases.add(testcase)
            size_testcase += 1



    for i, (n, m, g) in enumerate(list(testcases)):
        with open('input_{}.in'.format(i), 'w') as fout:
            fout.write('{} {}\n'.format(n, m))
            for s, t, c in g:
                fout.write('{} {} {}\n'.format(s, t, c))



if __name__ == "__main__":
    main()
