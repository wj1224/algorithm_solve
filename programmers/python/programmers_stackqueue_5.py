from functools import reduce

def solution(arrangement):
	answer = 0
	cnt = 0
	for i in range(len(arrangement) - 1):
		if arrangement[i] == "(" and arrangement[i + 1] == ")":
			answer += cnt
		elif arrangement[i] == "(" and arrangement[i + 1] == "(":
			cnt += 1
			answer += 1
		elif arrangement[i] == ")" and arrangement[i + 1] == ")":
			cnt -= 1
				
	return answer