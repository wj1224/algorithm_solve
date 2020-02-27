#!/bin/python3

import math
import os
import random
import re
import sys
from functools import reduce
from collections import Counter

# Complete the makeAnagram function below.
def makeAnagram(a, b):
	A = dict(Counter(a) - Counter(b))
	B = dict(Counter(b) - Counter(a))
	A_sum = 0; B_sum = 0
	if A:
		A_sum = reduce(lambda x, y: x + y, A.values())
	if B:
		B_sum = reduce(lambda x, y: x + y, B.values())
	return A_sum + B_sum

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	a = input()

	b = input()

	res = makeAnagram(a, b)

	fptr.write(str(res) + '\n')

	fptr.close()
