def solution(n, words):
	answer = [0, 0]
	d = {}
	idx_d = {}
	idx = 1
	prev = words[0][0]
	
	for w in words:
		d[w] = d.get(w, 0) + 1
		idx_d[idx] = idx_d.get(idx, 0) + 1
		if prev[-1] != w[0] or d[w] == 2:
			answer = [idx, idx_d[idx]]
			break
		if idx < n:
			idx += 1
		else:
			idx = 1
		prev = w

	return answer
