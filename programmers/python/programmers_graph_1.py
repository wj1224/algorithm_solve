def solution(n, edge):
	answer = 0
	maxval = -1
	q = []
	edge_dict = {}
	len_node = {}
	for x in range(1, n + 1):
		edge_dict[x] = edge_dict.get(x, [])
		len_node[x] = len_node.get(x, 99999)
	len_node[1] = 0
	for e in edge:
			edge_dict[e[0]].append(e[1])
			edge_dict[e[1]].append(e[0])
	q.append(1)
	while q:
		cur = q.pop(0)
		for i in edge_dict[cur]:
			if len_node[i] > len_node[cur] + 1:
				len_node[i] = len_node[cur] + 1
				maxval = len_node[i] if len_node[i] > maxval else maxval
				q.append(i)
	for key, val in len_node.items():
		answer += 1 if val == maxval else 0
	return answer