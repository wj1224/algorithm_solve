# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from collections import Counter

def solution(A):
	# write your code in Python 3.6
	ans = -1
	if len(A) != 0:
		d = dict(Counter(A))
		maxval = max(d.keys(), key=lambda x: d[x])
		if d[maxval] > len(A) / 2:
			ans = A.index(maxval)
	return ans
