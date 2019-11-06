def solution(numbers):
	answer = ''
	numbers = [str(x) for x in numbers]
	numbers.sort(key=lambda x: (x * 4)[:4], reverse=True)
	if numbers[0] == '0':
		answer = '0'
	else:
		for x in numbers:
			answer += x
	return answer