#!/usr/bin/env python3

from fractions import Fraction

def solve_up(n, k, offset):
    if k == 0:
        assert n <= 6
        if n <= 4:
            return (offset[0], offset[1] + Fraction(n, 4))
        else:
            return (offset[0] + Fraction(n - 4, 4), offset[1] + 1)
    else:
        mid = 6*2**(k-1)
        offset = offset if n < mid else (offset[0] + 2**(k-1), offset[1] + 2**(k-1))
        return solve_up(n % mid, k-1, offset)

def solve_down(n, k, offset):
    if k == 0:
        assert n <= 3
        if n <= 2:
            return (offset[0] - Fraction(n, 2), offset[1])
        else:
            return (offset[0] - 1, offset[1] - (n - 2))
    else:
        mid = 3*2**(k-1)
        offset = offset if n < mid else (offset[0] - 2**(k-1), offset[1] - 2**(k-1))
        return solve_down(n % mid, k-1, offset)

def format_fraction(f):
    if f.denominator == 1:
        return str(f.numerator)
    return "{}/{}".format(f.numerator, f.denominator)

k, n = tuple(map(int, input().split()))

v = 2**k
n *= 2
total_time = v*9

n %= total_time

if n < 6*v:
    ans = solve_up(n, k, (Fraction(0), Fraction(0)))
else:
    ans = solve_down(n - 6*v, k, (Fraction(v), Fraction(v)))

print("{} {}".format(format_fraction(ans[0] / 2**k), format_fraction(ans[1] / 2**k)))
