#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countSwaps function below.
def countSwaps(a):
	n_swaps = 0
	for i in range(len(a)):
		for j in range(len(a) - 1):
			if a[j] > a[j + 1]:
				a[j + 1], a[j] = a[j], a[j + 1]
				n_swaps += 1
	first_element = a[0]; last_element = a[-1]
	print("Array is sorted in {} swaps.".format(n_swaps))
	print("First Element: {}".format(first_element))
	print("Last Element: {}".format(last_element))
	return

if __name__ == '__main__':
	n = int(input())

	a = list(map(int, input().rstrip().split()))

	countSwaps(a)
