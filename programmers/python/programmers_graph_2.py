def solution(n, results):
	answer = 0
	n_dict = {}
	results.sort()
	for i in range(n):
		n_dict[i + 1] = n_dict.get(i + 1, [set(), set()])
	for i in range(n):
		for r in results:
			n_dict[r[0]][0].add(r[1])
			n_dict[r[1]][1].add(r[0])
		for key, val in n_dict.items():
			for s in val[0]:
				val[0] = val[0] | n_dict[s][0]
			for s in val[1]:
				val[1] = val[1] | n_dict[s][1]
	for key, val in n_dict.items():
		answer += 1 if len(val[0]) + len(val[1]) == n - 1 else 0
	return answer