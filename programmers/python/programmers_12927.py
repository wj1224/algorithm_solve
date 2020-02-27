import heapq as hq

def solution(n, works):
	answer = 0
	
	for i in range(len(works)):
		works[i] *= -1
	hq.heapify(works)
	while n > 0 and works[0] != 0:
		num = hq.heappop(works)
		hq.heappush(works, num + 1)
		n -= 1
	for w in works:
		answer += w ** 2
		
	return answer
