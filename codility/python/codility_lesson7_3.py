# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
	# write your code in Python 3.6
	ans = 1
	stack = []
	for s in S:
		if s == "(":
			stack.append(s)
		else:
			if len(stack) != 0:
				stack.pop()
			else:
				ans = 0
				break
	if len(stack) != 0:
		ans = 0
	return ans
