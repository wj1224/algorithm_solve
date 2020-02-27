# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	answer = 0
	A = sorted(A, reverse=True)
	for i in range(len(A) - 2):
		if A[i] < A[i + 1] + A[i + 2] and \
		A[i + 1] < A[i] + A[i + 2] and \
		A[i + 2] < A[i] + A[i + 1]:
			answer = 1
	return answer
