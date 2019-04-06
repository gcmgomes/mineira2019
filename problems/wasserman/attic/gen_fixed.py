#!/usr/bin/env python

import sys,os,string
from random import seed, randint, sample, choice

# first argument is always seed
seed(sys.argv[1])
T=int(sys.argv[2])

if T == 6:
	print """1
asd
a
asd"""

if T == 1:
	print """5
blohblo
aos competidores
bloh
ajuda
blobla
aos artistas da
ubl
Peca
blaubl
da Maratona Mineira
ublblohbloblaubl"""

if T == 2:
	print """6
a
a
ab
ave
blu
peixe
blua
tubarao
lu
voa
luaa
mar
abluluab"""

if T == 3:
	print """4
a
go
d
lets
dadadadadadadaadadadadddddadadadadadaaada
end
ab
our end
dadadadadadadaadadadadddddadadadadadaaadab"""

if T == 4:
	print """4
a
go
d
lets
dadadadadadadaadadadadddddadadadadadaaada
end
ab
our end
dadadadadadadaadadadadddddadadadadadaaadaab"""

if T == 5:
	def gen_word(len):
		return ''.join([choice(string.ascii_letters) for i in range(len)])

	N = 50000
	words = []

	phrase = "abzxcasdUlqwertySDFGREERerEeRrRRRrrrreeeHJKLIOWa"
	words += [phrase[:2]]

	for i in range(N-2):
		words += [gen_word(50)]
	
	words += [phrase[2:]]

	print N
	for word in words:
		print word
		print gen_word(30)
	print phrase * 10000
