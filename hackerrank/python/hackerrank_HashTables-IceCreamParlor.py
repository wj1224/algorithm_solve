#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the whatFlavors function below.
def whatFlavors(cost, money):
	d = dict()
	for i in range(len(cost)):
		if money - cost[i] in d.keys():
			return print(d[money - cost[i]], i + 1)
		if cost[i] not in d.keys():
			d[cost[i]] = i + 1
			
if __name__ == '__main__':
	t = int(input())

	for t_itr in range(t):
		money = int(input())

		n = int(input())

		cost = list(map(int, input().rstrip().split()))

		whatFlavors(cost, money)
