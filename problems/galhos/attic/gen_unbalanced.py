#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample, shuffle

# first argument must be seed
seed(sys.argv[1])
max_n, max_k = int(sys.argv[2]), int(sys.argv[3])

n = randint(1, max_n)

hs, es, vat = list(range(n)), [], {}
shuffle(hs)

for i, h in enumerate(hs):
    vat[h] = i

for i in range(n):
    if hs[i] == 0:
        es.append(-1)
    else:
        es.append(1 + vat[randint(max(0, hs[i] - max_k), hs[i] - 1)])

print(n)
print(" ".join(map(str, es)))

b = list(range(1, n+1))
shuffle(b)

print(" ".join(map(str, b)))
