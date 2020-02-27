# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
	# write your code in Python 3.6
	answer = -1
	s = set()
	for i, v in enumerate(A):
		s.add(v)
		if len(s) == X:
			answer = i
			break
	return answer
