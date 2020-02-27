import heapq as hq

def solution(N, road, K):
	min_len = [9999999 for _ in range(N + 1)]
	min_len[1] = 0
	d = {}
	pq = []
	answer = 0
	
	for start, end, cost in road:
		if start > end:
			start, end = end, start
		d[start] = d.get(start, []) + [[end, cost]]
		d[end] = d.get(end, []) + [[start, cost]]
		if start == 1:
			hq.heappush(pq, [cost, start])
	while pq:
		_, start = hq.heappop(pq)
		for end, cost in d[start]:
			if min_len[start] + cost < min_len[end]:
				min_len[end] = min_len[start] + cost
				hq.heappush(pq, [min_len[start] + cost, end])
	for k in min_len:
		answer += 1 if k <= K else 0
	
	return answer
