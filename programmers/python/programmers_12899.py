def solution(n):
	answer = []
	while n / 3 >= 1:
		a = n % 3
		if a != 0:
			answer.append(a)
			n = n // 3
		else:
			answer.append(4)
			n = n // 3 - 1
	if n != 0:
		answer.append(n)
	return ''.join(list(map(str, answer[::-1])))
