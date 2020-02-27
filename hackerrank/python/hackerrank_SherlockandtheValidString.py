#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Complete the isValid function below.
def isValid(s):
	cnt = list(Counter(s).values())
	valid = set(cnt)
	if len(valid) > 2:
		return "NO"
	elif len(valid) == 1:
		return "YES"
	max_index = cnt.index(max(cnt))
	cnt[max_index] -= 1
	valid = set(cnt)
	if len(valid) == 1:
		return "YES"
	cnt[max_index] += 1
	if 1 in cnt:
		cnt.remove(1)
	else: return "NO"
	valid = set(cnt)
	if len(valid) == 1:
		return "YES"
	else:
		return "NO"

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	s = input()

	result = isValid(s)

	fptr.write(result + '\n')

	fptr.close()
