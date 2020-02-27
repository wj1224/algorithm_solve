def solution(skill, skill_trees):
	answer = 0
	for s in skill_trees:
		skill_temp = list(skill)
		valid = True
		for c in s:
			if c in skill_temp:
				if c == skill_temp[0]:
					skill_temp.pop(0)
				else:
					valid = False
					break
		answer += 1 if valid else 0
	return answer
