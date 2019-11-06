def solution(prices):
	answer = []
	p = []
	idx = 0
	for i in range(len(prices)):
		answer.append(len(prices) - 1 - i)
	while idx < len(prices):
		if len(p) == 0 or prices[idx] >= p[-1][0]:
			p.append([prices[idx], idx])
			idx += 1
		elif prices[idx] < p[-1][0]:
			answer[p[-1][1]] = idx - p[-1][1]
			p.pop()
	return answer