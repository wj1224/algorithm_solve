def solution(n, s):
	answer = []
	
	if n > s:
		return [-1]
	
	num = s // n
	remain = s % n
	
	for i in range(n):
		if i < n - remain:
			answer.append(num)
		else:
			answer.append(num + 1)
	
	return answer
