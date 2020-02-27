#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the stepPerms function below.
d = {1: 1, 2: 2, 3: 4}

def stepPerms(n):
	if n in d.keys():
		return d[n]
	else:
		d[n] = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3)
		return d[n]

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	s = int(input())

	for s_itr in range(s):
		n = int(input())

		res = stepPerms(n)

		fptr.write(str(res) + '\n')

	fptr.close()
