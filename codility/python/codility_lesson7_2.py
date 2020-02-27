# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, B):
	# write your code in Python 3.6
	ans = 0
	stack = []
	for a, b in zip(A, B):
		if len(stack) == 0 and b == 0:
			ans += 1
		elif b == 1:
			stack.append(a)
		elif b == 0:
			while len(stack) != 0 and a > stack[-1]:
				stack.pop()
			if len(stack) == 0:
				ans += 1
	ans += len(stack)
	return ans
