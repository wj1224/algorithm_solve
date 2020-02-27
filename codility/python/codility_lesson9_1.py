# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	ans = 0
	if len(A) != 0:
		minval = A[0]
		for a in A:
			if a - minval > ans:
				ans = a - minval
			if a < minval:
				minval = a
	return ans
