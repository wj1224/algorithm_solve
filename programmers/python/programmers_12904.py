def solution(s):
	mem = []
	answer = 1
	for i in range(len(s)):
		mem.append([])
		for j in range(len(s)):
			if i == j or (i + 1 == j and s[i] == s[j]):
				mem[i].append(True)
				if i != j:
					answer = 2
			else:
				mem[i].append(False)
	for i in range(2, len(s)):
		for j in range(len(s) - i):
			if s[j] == s[j + i] and mem[j + 1][j + i - 1] is True:
				mem[j][j + i] = True
				answer = max(answer, i + 1)
	return answer
