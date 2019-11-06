def solution(priorities, location):
	answer = 1
	while len(priorities) != 0:
		if priorities[0] >= max(priorities):
			if location == 0:
				break
			else:
				priorities.pop(0)
				location -= 1
				answer += 1
		else:
			priorities.append(priorities.pop(0))
			location += (len(priorities) - 1) if location == 0 else -1
	return answer