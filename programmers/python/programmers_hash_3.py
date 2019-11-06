def solution(clothes):
	clo = {}
	answer = 1
	for c in clothes:
		clo[c[1]] = clo.get(c[1], 0) + 1
	for key, val in clo.items():
		answer *= (val + 1)
	answer -= 1
	return answer
