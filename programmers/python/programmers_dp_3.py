def solution(triangle):
	answer = [list() for _ in range(len(triangle))]
	answer[0].append(triangle[0][0])
	idx = 0
	while idx + 1 < len(triangle):
		answer[idx + 1].append(answer[idx][0] + triangle[idx + 1][0])
		for i in range(len(answer[idx])):
			if i == 0:
				continue
			else:
				answer[idx + 1].append(max(answer[idx][i - 1] + triangle[idx + 1][i], answer[idx][i] + triangle[idx + 1][i]))
		answer[idx + 1].append(answer[idx][-1] + triangle[idx + 1][-1])
		idx += 1
	return max(answer[-1])