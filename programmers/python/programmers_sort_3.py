def solution(citations):
	answer = 0
	citations.sort()
	for idx, val in enumerate(citations):
		key = len(citations) - idx
		if key <= val:
			return key
	return answer