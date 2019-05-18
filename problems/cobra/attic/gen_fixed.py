#!/usr/bin/env python

import sys,os,string
from random import seed, randint, sample

# first argument is always seed
seed(sys.argv[1])
min_i=int(sys.argv[2])
max_i=int(sys.argv[3])

for i in range(min_i,max_i+1):
	print i

print 0