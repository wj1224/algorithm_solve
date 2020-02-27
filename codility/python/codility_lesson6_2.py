# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from collections import Counter

def solution(A):
	# write your code in Python 3.6
	d = dict(Counter(A))
	return len(d)
