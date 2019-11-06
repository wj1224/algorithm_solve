# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
from functools import reduce

def solution(A):
	# write your code in Python 3.6
	left_sum = A[0]
	right_sum = reduce(lambda x, y: x + y, A[1:])
	minval = abs(left_sum - right_sum)
	for i in range(1, len(A) - 1):
		left_sum += A[i]
		right_sum -= A[i]
		minval = min(minval, abs(left_sum - right_sum))
	return minval