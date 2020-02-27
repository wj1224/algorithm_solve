def solution(n):
	answer = 0
	
	for i in range(1, n // 2 + 2):
		num = i
		for j in range(i + 1, n // 2 + 2):
			num += j
			if num == n:
				answer += 1
			if num >= n:
				break
	
	return answer + 1
