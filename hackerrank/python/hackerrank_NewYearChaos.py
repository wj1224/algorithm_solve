#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
	answer = 0
	for idx, val in enumerate(q):
		if val - (idx + 1) > 2:
			return print("Too chaotic")
		for j in range(max(0, val - 2), idx):
			answer += 1 if q[j] > val else 0
	return print(answer)

if __name__ == '__main__':
	t = int(input())

	for t_itr in range(t):
		n = int(input())

		q = list(map(int, input().rstrip().split()))

		minimumBribes(q)
