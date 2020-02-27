def search(n, start, mid, end, answer):
	if n == 1:
		answer.append([start, end])
	else:
		search(n - 1, start, end, mid, answer)
		search(1, start, mid, end, answer)
		search(n - 1, mid, start, end, answer)
	return answer

def solution(n):
	answer = []
	search(n, 1, 2, 3, answer)
	return answer
