#!/usr/bin/env python2

import sys,os,string
from random import seed, randint, sample, choice, shuffle

def gen_name(length):
	return ''.join(choice(string.ascii_lowercase) for i in range(length))

# first argument is always seed
seed(sys.argv[1])
N=int(sys.argv[2])

# participantes
names = [gen_name(10) for i in range(N)]
# sorteio
indexes = [i for i in range(N)]
for i in range(N):
	target = i
	while (indexes[target] == i and indexes[i] == target):
		target = randint(0, N-1)
	indexes[i], indexes[target] = indexes[target], indexes[i]

# mentiroso
id_liar = randint(0, N-1)
id_lie = id_liar
while (id_lie == id_liar):
	id_lie = randint(0, N-1)
indexes[id_liar] = indexes[id_lie]

print N 
for i in range(N):
	print names[i], names[indexes[i]]
