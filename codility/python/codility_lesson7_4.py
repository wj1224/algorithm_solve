# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(H):
	# write your code in Python 3.6
	ans = 0
	stack = []
	for h in H:
		if len(stack) == 0 or stack[-1] < h:
			stack.append(h)
			ans += 1
		elif stack[-1] > h:
			while len(stack) != 0 and stack[-1] > h:
				stack.pop()
			if len(stack) == 0 or stack[-1] != h:
				stack.append(h)
				ans += 1
	return ans
