#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample

# first argument must be seed
seed(sys.argv[1])
qtd = int(sys.argv[2])
max_n = int(sys.argv[3])

for i in range(qtd):
	n = randint(1, max_n)
	print n
print 0
