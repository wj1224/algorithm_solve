def check(queen, x, y):
	for i in range(y):
		if (x == queen[i]) or (abs(x - queen[i]) == y - i):
			return False
	return True

def dfs(idx, n, y, queen, answer):
	if idx == n:
		return answer + 1
	for i in range(n):
		if check(queen, i, y):
			answer = dfs(idx + 1, n, y + 1, queen + [i], answer)
	return answer

def solution(n):
	answer = dfs(0, n, 0, [], 0)
	return answer
