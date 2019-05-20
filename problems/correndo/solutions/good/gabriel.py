#!/usr/bin/python3

import math

b, a = [int(x) for x in input().split()]

ang = 2 * (math.pi / 2 - math.asin(a / b))
print(int(math.ceil(math.pi * 2 / ang)))
