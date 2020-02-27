def solution(s):
	stack = []
	
	for word in s:
		if len(stack) == 0:
			stack.append(word)
		else:
			if stack[-1] == word:
				stack.pop()
			else:
				stack.append(word)
	answer = 1 if len(stack) == 0 else 0
	
	return answer
