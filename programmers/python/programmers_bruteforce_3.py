import itertools

def solution(baseball):
	answer = 0
	l = list(map(''.join, itertools.permutations(map(str, list(range(1, 10))), 3)))
	for i in l:
		for num, target in enumerate(baseball, 1):
			strike = 0
			ball = 0
			for idx in range(3):
				if str(target[0])[idx] in i:
					if str(target[0])[idx] == i[idx]:
						strike += 1
					else:
						ball += 1
			if strike != target[1] or ball != target[2]:
				break
			if num == len(baseball):
				answer += 1
				
	return answer