# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
	# write your code in Python 3.6
	ans = 0
	for i in range(1, int(N ** 0.5) + 1):
		if i ** 2 == N:
			ans += 1
		elif N % i == 0:
			ans += 2
	return ans
