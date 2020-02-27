#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubsetSum function below.
def maxSubsetSum(arr):
	mem = [0] * len(arr)
	mem[0] = arr[0]
	mem[1] = max(mem[0], arr[1])
	for i in range(2, len(arr)):
		mem[i] = max(arr[i], mem[i - 1], mem[i - 2] + arr[i])
	return mem[-1]

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	arr = list(map(int, input().rstrip().split()))

	res = maxSubsetSum(arr)

	fptr.write(str(res) + '\n')

	fptr.close()
