#!/usr/bin/env python3
import random

NUM_TESTCASE = 40
MIN_LENGTH = 1
MAX_LENGTH = 50

testcases = set()
testcases.add(('b', 'BB'))
testcases.add(('Bb', 'BBB'))
testcases.add(('b', 'b'))
testcases.add(('BbB', 'b'))
testcases.add(('BBBBBBBB', 'b'))
testcases.add(('B'*MAX_LENGTH, 'B'*MAX_LENGTH))

size_testcase = len(testcases)

while size_testcase < NUM_TESTCASE:
    len_s = random.randint(MIN_LENGTH, MAX_LENGTH-1)
    s = 'B' + ''.join(random.choice('bB') for _ in range(len_s))
    len_t = random.randint(MIN_LENGTH, MAX_LENGTH-1)
    t = 'B' + ''.join(random.choice('bB') for _ in range(len_t))
    if (s, t) not in testcases:
        testcases.add((s, t))
        size_testcase += 1

for i, (s, t) in enumerate(list(testcases)):
    with open('input_{}.in'.format(i), 'w') as fout:
        fout.write('{}\n{}\n'.format(s, t))

exit(0)
