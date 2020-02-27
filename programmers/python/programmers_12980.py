def solution(n):
	answer = 1
	while n >= 2:
		div, mod = n // 2, n % 2
		n //= 2
		answer += 1 if mod == 1 else 0

	return answer
