# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	minval = 99999999
	ans = 0
	for i in range(len(A)):
		min1 = (A[i] + A[i + 1]) / 2 if i + 1 < len(A) else 99999999
		min2 = (A[i] + A[i + 1] + A[i + 2]) /3 if i + 2 < len(A) else 99999999
		if minval > min1:
			minval = min1
			ans = i
		if minval > min2:
			minval = min2
			ans = i
	return ans
