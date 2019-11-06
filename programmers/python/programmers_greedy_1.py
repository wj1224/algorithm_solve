def solution(n, lost, reserve):
	l = [1] * (n + 2)
	for i in lost:
		l[i] -= 1
	for i in reserve:
		l[i] += 1
	for i in range(1, n + 1):
		if l[i] == 2:
			if l[i - 1] == 0:
				l[i - 1] = 1
				l[i] = 1
			elif l[i + 1] == 0:
				l[i + 1] = 1
				l[i] = 1
	answer = 0
	for i in range(1, n + 1):
		answer += 1 if l[i] > 0 else 0
	return answer