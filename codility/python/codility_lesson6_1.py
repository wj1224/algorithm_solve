# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
	# write your code in Python 3.6
	A_sort = sorted(A, reverse=True)
	answer = max(A_sort[0] * A_sort[1] * A_sort[2], A_sort[0] * A_sort[-1] * A_sort[-2])
	return answer
