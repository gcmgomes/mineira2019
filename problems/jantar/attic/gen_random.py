#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample

# first argument must be seed
seed(sys.argv[1])
max_n = int(sys.argv[2])
max_m = int(sys.argv[3])

n = randint(1, max_n)
m = randint(1, max_m)
print("{} {}".format(n, m))
