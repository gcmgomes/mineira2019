#!/usr/bin/env python

import sys,os,string
from random import seed, randint, sample, shuffle


def gen_unique_numbers(n, a, b):
    '''
        Generates n unique numbers from a to b, inclusive.
    '''

    random_numbers = set()
    while len(random_numbers) < n:
        random_numbers.add(randint(a, b))
    return list(random_numbers)


def fix_testcase(teams):
    '''
        Ensures that the test case doesn't have two teams with same number
        of problems and penalty.
    '''

    neue_teams = []
    for t in teams:
        neue_teams.append([t[1], -t[2], t[0]])
    
    deu_ruim = True
    while deu_ruim:
        last_p = -1
        last_t = 0
        deu_ruim = False
        neue_teams.sort()
        for idx in range(len(neue_teams)):
            team = neue_teams[idx]
            if last_p == team[0] and last_t == team[1]:
                neue_teams[idx][1] -= randint(1, 5)
                deu_ruim = True
                break
            else:
                last_p = team[0]
                last_t = team[1]

    ret_teams = []
    for t in neue_teams:
        ret_teams.append((t[2], t[0], -t[1]))
    return ret_teams


def gen(n, k):
    '''
        Generates a test case given n and k.

        params:
         n: The number of teams.
         k: The position of the team that receives the cool prize.
    '''

    teams = []
    cur_idx = 0
    for t in range(n):
        cur_idx += 1
        n_problems = randint(0, 13)
        penalty = randint(1, 950)
        teams.append((cur_idx, n_problems, penalty))
    
    teams = fix_testcase(teams)

    shuffle(teams)
    print n, k
    for t in teams:
        print t[0], t[1], t[2]


if __name__ == '__main__':
  # first argument is always seed
  seed(sys.argv[1])
  N = int(sys.argv[2])
  K = int(sys.argv[3])
  gen(N, K)
