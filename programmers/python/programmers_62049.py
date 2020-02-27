def solution(n):
	answer = [0]
	for i in range(2, n + 1):
		insert_list = answer[:]
		answer.append(0)
		for j in range(len(insert_list) - 1, -1, -1):
			answer += [1] if insert_list[j] == 0 else [0]
	return answer
