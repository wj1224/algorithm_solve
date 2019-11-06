def solution(participant, completion):
	d = {}
	answer = []
	for i in participant:
		d[i] = d.get(i, 0) + 1
	for i in completion:
		d[i] -= 1
	for i in d:
		if d[i] > 0:
			answer.append(i)
	return answer[0]
