def solution(N, number):
	answer = -1
	num = [set() for x in range(8)]
	for idx, val in enumerate(num, start=1):
		val.add(int(str(N) * idx))
	for i in range(8):
		for j in range(i):
			for num1 in num[j]:
				for num2 in num[i - j - 1]:
					num[i].add(num1 + num2)
					num[i].add(num1 - num2)
					num[i].add(num1 * num2)
					if num2 != 0:
						num[i].add(num1 // num2)
		if number in num[i]:
			answer = i + 1
			break
					
	return answer