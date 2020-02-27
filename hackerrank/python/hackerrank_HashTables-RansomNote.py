#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
	answer = "Yes"
	magazine_dict = dict()
	for m in magazine:
		magazine_dict[m] = magazine_dict.get(m, 0) + 1
	for n in note:
		if n in magazine_dict.keys():
			if magazine_dict[n] != 0:
				magazine_dict[n] -= 1
			else:
				answer = "No"
		else:
			answer = "No"
	print(answer)
	return

if __name__ == '__main__':
	mn = input().split()

	m = int(mn[0])

	n = int(mn[1])

	magazine = input().rstrip().split()

	note = input().rstrip().split()

	checkMagazine(magazine, note)
