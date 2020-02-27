# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from collections import Counter

def solution(A):
	# write your code in Python 3.6
	c = dict(Counter(A))
	answer = 1
	for i in range(1, len(A) + 2):
		if not i in c.keys():
			answer = i
			break
	return answer
