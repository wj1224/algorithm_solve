#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(arr):
	arr.sort()
	cur = arr[0]
	answer = 9999999
	for i in range(1, len(arr)):
		answer = min(answer, abs(cur - arr[i]))
		cur = arr[i]
	return answer

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	arr = list(map(int, input().rstrip().split()))

	result = minimumAbsoluteDifference(arr)

	fptr.write(str(result) + '\n')

	fptr.close()
