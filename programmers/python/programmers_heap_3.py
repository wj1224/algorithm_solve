import heapq as hq

def solution(jobs):
	answer = 0
	cnt = 0
	num = len(jobs)
	order = []
	jobs.sort()
	while True:
		if not jobs and not order:
			break
		while jobs and cnt >= jobs[0][0]:
			hq.heappush(order, [jobs[0][1], jobs[0][0]])
			jobs.pop(0)
		if order:
			temp = hq.heappop(order)
			cnt += temp[0]
			answer += (cnt - temp[1])
			continue
		cnt += 1
	answer //= num
	return answer