def solution(heights):
	answer = [0]
	for idx, val in enumerate(heights[1:], 1):
		id = idx
		for i, s in enumerate(reversed(heights[:idx])):
			if val < s:
				answer.append(id)
				break
			if i == len(heights[:idx]) - 1:
				answer.append(0)
			id -= 1
	return answer