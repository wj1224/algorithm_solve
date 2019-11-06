from functools import reduce

def solution(people, limit):
	answer = 0
	people.sort()
	check = [1] * len(people)
	l_idx = 0
	r_idx = len(people) - 1
	while True:
		if l_idx >= r_idx:
			break
		if people[l_idx] + people[r_idx] <= limit:
			check[l_idx] = 0
			check[r_idx] = 0
			answer += 1
			l_idx += 1
			r_idx -= 1
		else:
			r_idx -= 1
	answer += reduce(lambda x, y: x + y, check)
	return answer