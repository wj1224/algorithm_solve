#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
	bracket_dict = {"[": "]", "{" : "}", "(" : ")"}
	stack = []
	for bracket in s:
		if bracket in ["[", "{", "("]:
			stack.append(bracket)
		else:
			if len(stack) != 0 and bracket == bracket_dict[stack[-1]]:
				stack.pop()
			else:
				return "NO"
	if len(stack) == 0:
		return "YES"
	else:
		return "NO"

if __name__ == '__main__':
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	t = int(input())

	for t_itr in range(t):
		s = input()

		result = isBalanced(s)

		fptr.write(result + '\n')

	fptr.close()
