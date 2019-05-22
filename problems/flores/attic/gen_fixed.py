#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample, random, randrange

def bitInativo(x, bit):
    if x&(1<<bit):
		return 0
    return 1
	
lista = []
def positionGenerator(ini, fim):
	valor = randint(ini, fim)
	while valor in lista: 
		valor = randint(ini, fim)
	lista.append(valor)
	return valor;

# first argument must be seed
seed(sys.argv[1])
L = int(sys.argv[2])
C = int(sys.argv[3])
T = int(sys.argv[4])
S = int(sys.argv[5])
AA = int(sys.argv[6])
BB = int(sys.argv[7])
CC = int(sys.argv[8])
DD = int(sys.argv[9])

print L, C, T

TT = 2**T
	
if S<2:
	if S==0:
		linhaA = positionGenerator(0, L-1)
		colunaA = positionGenerator(0, C-1)
		linhaB = positionGenerator(0, L-1)	
		colunaB = positionGenerator(0, C-1)
		
	elif S==1:

		linhaA = 1
		colunaA = 1
		linhaB = L-2
		colunaB = C-2

	linhaC = positionGenerator(0, L-1)
	colunaC = positionGenerator(0, C-1)
	linhaD = positionGenerator(0, L-1)
	colunaD = positionGenerator(0, C-1)

	for i in range(L):
		for j in range(C):
			if(i==linhaA and j==colunaA):
				valor = (1<<AA)
			elif(i==linhaB and j==colunaB):
				valor = (1<<BB)
			elif(i==linhaC and j==colunaC):
				valor = (1<<CC)
			elif(i==linhaD and j==colunaD):
				valor = (1<<DD)
			else:
				while 1:
					valor = randint(0, TT-1)
					if bitInativo(valor, AA) and bitInativo(valor, BB) and bitInativo(valor, CC) and bitInativo(valor, DD):
						break				
			if(j<C-1):
				print valor,
			else:
				print valor
					
else:
	for i in range(L):
		for j in range(C):
			if(j<C-1):
				print randrange(0, TT, 2),
			else:
				print randrange(0, TT, 2)
