#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample

# first argument must be seed
seed(sys.argv[1])
min_n=int(sys.argv[2])
max_n = int(sys.argv[3])
n = randint(min_n, max_n)
print n
