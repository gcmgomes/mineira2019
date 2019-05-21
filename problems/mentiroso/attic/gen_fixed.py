#!/usr/bin/env python2

import sys,os,string
from random import seed, randint, sample, choice, shuffle

def gen_name(length):
	return ''.join(choice(string.ascii_lowercase) for i in range(length))

# first argument is always seed
seed(sys.argv[1])
N=int(sys.argv[2])

# participantes
names = [gen_name(10) for i in range(N-1)]
liar = gen_name(10)

#sorteio
edges = [(names[i], names[(i+1)%(N-1)]) for i in range(N-1)]
edges += [(liar, names[randint(0, N-1)])]

shuffle(edges)

print N 
for a, b in edges:
	print a, b
