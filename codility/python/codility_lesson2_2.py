# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, K):
	# write your code in Python 3.6
	B = []
	answer = [0] * len(A)
	for i in range(len(A)):
		B.append((((i + 1) + K) % len(A)) - 1)
	for a, b in zip(A, B):
		answer[b] = a
	return answer