def solution(tickets):
	answer = []
	s = ["ICN"]
	airport = {}
	for t in tickets:
		airport[t[0]] = airport.get(t[0], []) + [t[1]]
	for key, val in airport.items():
		val.sort(reverse=True)
	while s:
		cur = s[-1]
		if cur not in airport or len(airport[cur]) == 0:
			answer.append(s.pop())
		else:
			s.append(airport[cur][-1])
			airport[cur].pop()

	return answer[::-1]