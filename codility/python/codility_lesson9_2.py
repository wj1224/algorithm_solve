# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	mem = [0] * len(A)
	mem[0] = A[0]
	for i in range(1, len(A)):
		mem[i] = max(A[i] + mem[i - 1], A[i])
	return max(mem)
