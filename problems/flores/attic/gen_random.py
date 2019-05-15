#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample, random

# first argument must be seed
seed(sys.argv[1])
L = int(sys.argv[2])
C = int(sys.argv[3])
T = int(sys.argv[4])

print L, C, T

TT = 2**T

print("{} {}".format(L, C))

for i in range(L):
	for j in range(C):
		if(j<C-1):
			print randint(0, TT-1),
		else:
			print randint(0, TT-1)
