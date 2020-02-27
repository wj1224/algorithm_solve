def solution(nums):
	mon = {}
	for n in nums:
		mon[n] = mon.get(n, 0) + 1
	
	check = True
	answer = 0
	idx = 0
	while True:
		for key, val in mon.items():
			if val != 0 and check:
				answer += 1
				mon[key] -= 1
			idx += 1
			if idx == len(nums) // 2:
				return answer
		check = False
