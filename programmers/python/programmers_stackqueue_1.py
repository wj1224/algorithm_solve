import math

def solution(progresses, speeds):
	answer = []
	completion = []
	for i in range(len(progresses)):
		completion.append(math.ceil((100 - progresses[i]) / speeds[i]))
	val = completion[0]
	answer.append(1)
	idx = 0
	for i in range(1, len(completion)):
		if completion[i] <= val:
			answer[idx] += 1
		else:
			val = completion[i]
			idx += 1
			answer.append(1)
	return answer