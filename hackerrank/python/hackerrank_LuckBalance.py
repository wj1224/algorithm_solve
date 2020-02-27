#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the luckBalance function below.
def luckBalance(k, contests):
	answer = 0
	contests.sort(key=lambda x: (-x[0], -x[1]))
	for c in contests:
		if c[1] == 0:
			answer += c[0]
		elif c[1] == 1 and k > 0:
			answer += c[0]
			k -= 1
		else:
			answer -= c[0]
	return answer

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	nk = input().split()

	n = int(nk[0])

	k = int(nk[1])

	contests = []

	for _ in range(n):
		contests.append(list(map(int, input().rstrip().split())))

	result = luckBalance(k, contests)

	fptr.write(str(result) + '\n')

	fptr.close()
