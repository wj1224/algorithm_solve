import heapq

def solution(scoville, K):
	heapq.heapify(scoville)
	answer = 0
	while True:
		if scoville[0] > K:
			break
		elif len(scoville) == 1 and scoville[0] < K:
			answer = -1
			break
		sco1 = heapq.heappop(scoville)
		sco2 = heapq.heappop(scoville)
		heapq.heappush(scoville, sco1 + (sco2 * 2))
		answer += 1
	return answer