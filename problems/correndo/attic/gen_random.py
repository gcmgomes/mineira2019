#!/usr/bin/env python

import sys,os,string
from random import seed, randint, sample

# first argument must be seed
seed(sys.argv[1])
max_n, max_k = int(sys.argv[2]), int(sys.argv[3])

n = randint(2, max_n)
m = randint(max(1, n - randint(1, max_k)), n - 1)
print("{} {}".format(n, m))
