def solution(number, k):
	num = []
	number = map(int, number)
	for i in number:
		while len(num) > 0 and k > 0 and num[-1] < i:
			num.pop()
			k -= 1
		num.append(i)
	if k > 0:
		del num[-k:]
	answer = ''.join(map(str, num))
	return answer