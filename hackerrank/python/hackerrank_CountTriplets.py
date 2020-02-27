#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countTriplets function below.
def countTriplets(arr, r):
	answer = 0
	dict1 = dict()
	dict2 = dict()
	for a in arr:
		if a in dict2.keys():
			answer += dict2[a]
		if a in dict1.keys():
			dict2[a * r] = dict2.get(a * r, 0) + dict1[a]
		dict1[a * r] = dict1.get(a * r, 0) + 1
	return answer

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	nr = input().rstrip().split()

	n = int(nr[0])

	r = int(nr[1])

	arr = list(map(int, input().rstrip().split()))

	ans = countTriplets(arr, r)

	fptr.write(str(ans) + '\n')

	fptr.close()
