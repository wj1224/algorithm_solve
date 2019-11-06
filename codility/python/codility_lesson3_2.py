# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	if len(A) == 0:
		return 1
	A.sort()
	if A[0] != 1:
		return 1
	for idx, val in enumerate(A):
		if val != idx + 1:
			return idx + 1
	return len(A) + 1