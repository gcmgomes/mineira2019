#!/usr/bin/env python

# Sample test generator

import sys,os,string,copy
from random import seed, randint, sample, choice, shuffle

MAXL = 50
ROOT= os.environ['ROOT']
TESTDIR=os.path.join(os.path.join(ROOT, 'build'), 'tests')
ATTICDIR=os.path.join(ROOT, 'attic')
DATA="data.txt"

def defineLetters(bits):
	tmp = []
	for l in string.ascii_letters:
		tmp += [l]
	shuffle(tmp)
	return tmp[:bits]

def constructPhrase(bits, size):
	letters = defineLetters(bits)
	word = ""
	for i in range(size):
		word += choice(letters)
	return word

def breakPhrase(phrase, k):
	words = []
	l = len(phrase)
	#print "k: " + str(k)
	while l > 0:
		lowbound = max(l - MAXL * (k - 1), 1)
		upperbound = min(l - k + 1, MAXL)
		#print lowbound, upperbound
		v = randint(lowbound, upperbound)
		#print "v: " + str(v)
		words += [phrase[len(phrase)-l:len(phrase)-l+v]]
		l -= v
		k -= 1
	return words


# first argument must be seed
seed(sys.argv[1])
# number of words
N = int(sys.argv[2])
# length of the phrase
T = int(sys.argv[3])
# number of used caracters
bits = int(sys.argv[4])

data = []
for line in open(os.path.join(ATTICDIR,DATA), "r"):
	data += [line[:-1]]

phrase = constructPhrase(bits, T)

words = set([])
min_words = (T + MAXL - 1) / MAXL

if (min_words == 0):
	min_words = 1

if (N < min_words):
	N = min_words + 1

if (N > T):
	N = T

while len(words) < N and N-len(words) > min_words:
	k = randint(min_words, N - len(words))
	if (k < N and k >= N - min_words):
		k = N
	for word in breakPhrase(phrase, k):
		words.add(word)
	if (bits == 1 and len(words) == MAXL):
		break

while (len(words) < N):
	words.add(constructPhrase(bits+1, MAXL))

print len(words)
for word in words:
	print word
	print choice(data)
print phrase


