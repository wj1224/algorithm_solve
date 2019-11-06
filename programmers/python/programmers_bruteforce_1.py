def solution(answers):
	answer = []
	num1 = [1, 2, 3, 4, 5]
	num2 = [2, 1, 2, 3, 2, 4, 2, 5]
	num3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
	ans = [0, 0, 0]
	for i, v in enumerate(answers):
		ans[0] += 1 if v == num1[i % 5] else 0
		ans[1] += 1 if v == num2[i % 8] else 0
		ans[2] += 1 if v == num3[i % 10] else 0
	maxval = max(ans)
	for i in range(len(ans)):
		if ans[i] == maxval:
			answer.append(i + 1)
	return answer