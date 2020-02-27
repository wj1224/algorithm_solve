# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	LtoR = [0] * len(A)
	RtoL = [0] * len(A)
	ans = 0
	for i in range(1, len(A)):
		LtoR[i] = max(0, LtoR[i - 1] + A[i])
	for i in range(len(A) - 2, 0, -1):
		RtoL[i] = max(0, RtoL[i + 1] + A[i])
	for i in range(1, len(A) - 1):
		ans = max(ans, LtoR[i - 1] + RtoL[i + 1])
	return ans
