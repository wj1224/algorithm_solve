#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the getMinimumCost function below.
def getMinimumCost(k, c):
	c.sort()
	p = dict()
	for i in range(k):
		p[i] = 0
	answer = 0
	idx = 0
	for i in range(len(c) -1, -1, -1):
		if p[idx] == 0:
			p[idx] = 1
			answer += c[i]
		else:
			answer += ((p[idx] + 1) * c[i])
			p[idx] += 1
		idx += 1
		if idx == k:
			idx = 0
	return answer

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	nk = input().split()

	n = int(nk[0])

	k = int(nk[1])

	c = list(map(int, input().rstrip().split()))

	minimumCost = getMinimumCost(k, c)

	fptr.write(str(minimumCost) + '\n')

	fptr.close()
