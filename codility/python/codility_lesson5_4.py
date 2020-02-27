# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, B, K):
	# write your code in Python 3.6
	return B // K + 1 if A == 0 else (B // K) - ((A - 1) // K) 
