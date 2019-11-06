def solution(weight):
	answer = 1
	weight.sort()
	for w in weight:
		if w > answer:
			break
		answer += w
	return answer