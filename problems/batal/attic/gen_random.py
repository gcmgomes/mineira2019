#!/usr/bin/env python2

# Sample test generator

import sys,os,string
from random import seed, randint, sample, random

# first argument must be seed
seed(sys.argv[1])
N = int(sys.argv[2])
Q = int(sys.argv[3])

print N, Q

coordinates = set()

while len(coordinates) < Q:
	coordinates.add((randint(1, N), randint(1, N)))

for (x, y) in coordinates:
	print x, y
