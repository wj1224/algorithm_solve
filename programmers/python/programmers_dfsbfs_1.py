answer = 0

def dfs(idx, n, num, numbers, target):
	if idx >= n:
		if num == target:
			global answer
			answer += 1
		return
	dfs(idx + 1, n, num + numbers[idx], numbers, target)
	dfs(idx + 1, n, num - numbers[idx], numbers, target)
	return

def solution(numbers, target):
	dfs(0, len(numbers), 0, numbers, target)
	return answer