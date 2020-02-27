# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from collections import Counter

def solution(A):
	# write your code in Python 3.6
	answer = 1
	d = dict(Counter(A))
	for i in range(1, len(A) + 1):
		if not i in d.keys() or d[i] != 1:
			answer = 0
			break
	return answer
