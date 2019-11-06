import heapq as hq

def solution(stock, dates, supplies, k):
	answer = 0
	idx = 0
	pq = []
	while True:
		if stock >= k:
			break
		for i in range(idx, len(dates)):
			if dates[i] <= stock:
				hq.heappush(pq, -supplies[idx])
				idx += 1
			else:
				break
		stock -= (hq.heappop(pq))
		answer += 1
	return answer