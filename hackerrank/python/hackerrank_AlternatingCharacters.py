#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the alternatingCharacters function below.
def alternatingCharacters(s):
	answer = 0
	cur = "C"
	for val in s:
		if val == cur:
			answer += 1
		else:
			cur = val
	return answer

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	q = int(input())

	for q_itr in range(q):
		s = input()

		result = alternatingCharacters(s)

		fptr.write(str(result) + '\n')

	fptr.close()
