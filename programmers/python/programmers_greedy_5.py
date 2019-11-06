def solution(routes):
	answer = 0
	routes.sort()
	begin = 30001
	end = 30002
	for r in routes:
		if r[0] < r[1]:
			if not (begin <= r[0] and r[0] <= end):
				answer += 1
				begin = r[0]
				end = r[1]
				continue
			begin = r[0] if r[0] > begin else begin
			end = r[1] if r[1] < end else end
		else:
			if not (begin <= r[1] and r[1] <= end):
				answer += 1
				begin = r[1]
				end = r[0]
				continue
			begin = r[1] if r[1] > begin else begin
			end = r[0] if r[0] < end else end
		
	return answer