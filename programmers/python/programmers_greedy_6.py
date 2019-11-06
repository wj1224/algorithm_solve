def solution(n, costs):
	answer = 0
	costs.sort(key=lambda x: x[2])
	cost = [costs[0][0]]
	while len(cost) < n:
		for i, c in enumerate(costs):
			if c[0] in cost or c[1] in cost:
				if c[0] in cost and c[1] in cost:
					continue
				elif c[0] in cost:
					cost.append(c[1])
					answer += c[2]
					costs.pop(i)
					break
				elif c[1] in cost:
					cost.append(c[0])
					answer += c[2]
					costs.pop(i)
					break
	return answer