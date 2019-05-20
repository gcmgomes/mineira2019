#!/usr/bin/env python

import sys,os,string
from random import seed, randint, sample

# first argument must be seed
seed(sys.argv[1])
max_n = int(sys.argv[2])

n = randint(1, max_n)
m = n + randint(1, max_n)
print("{} {}".format(m, n))
