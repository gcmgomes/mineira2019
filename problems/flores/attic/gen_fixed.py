#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample, random, randrange

# first argument must be seed
seed(sys.argv[1])
L = int(sys.argv[2])
C = int(sys.argv[3])
T = int(sys.argv[4])
S = int(sys.argv[5])

print L, C, T

TT = 2**T

if(S==0):

	for i in range(L):
		for j in range(C):
			if(j<C-1):
				print randrange(0, TT, 2),
			else:
				print randrange(0, TT, 2)
				
elif(S>0):
	
	if(S==1):
		linhaImpar = randint(0, L-2)
		colunaImpar = randint(0, C-2)
	elif(S==2):
		linhaImpar = 1
		colunaImpar = 1
	elif(S==3):
		linhaImpar = L-1
		colunaImpar = C-1
	
	for i in range(L):
		for j in range(C):
			if(i==linhaImpar and j==colunaImpar):
				valor = 1
			else:
				valor = randrange(0, TT, 2)
			if(j<C-1):
				print valor,
			else:
				print valor
