#!/usr/bin/env python

# Sample test generator

import sys,os,string
from random import seed, randint, sample
from gen_fixed import gen



if __name__ == '__main__':
    # first argument must be seed
    seed(sys.argv[1])
    min_n = int(sys.argv[2])
    max_n = int(sys.argv[3])
    n = randint(min_n, max_n)
    k = randint(1, n)
    gen(n, k)
