#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample

# first argument must be seed
seed(sys.argv[1])
max_k = int(sys.argv[2])
max_n = int(sys.argv[3])

k = randint(0, max_k)
n = randint(0, max_n)

print("{} {}".format(k, n))
