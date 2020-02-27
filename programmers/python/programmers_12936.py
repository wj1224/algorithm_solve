import math

def solution(n, k):
	answer = []
	people = [x for x in range(1, n + 1)]
	people_idx = 0
	num = len(people)
	
	while len(answer) < n:
		if math.factorial(num - 1) < k:
			k -= math.factorial(num - 1)
			people_idx += 1
		else:
			answer.append(people[people_idx])
			people.remove(people[people_idx])
			num = len(people)
			people_idx = 0
	return answer
