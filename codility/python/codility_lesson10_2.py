# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
	# write your code in Python 3.6
	AB = []
	for i in range(1, int(N ** 0.5) + 1):
		if N % i == 0:
			AB.append([i, N // i])
	return min(list(map(lambda x: 2 * (x[0] + x[1]), AB)))
